#include <avr/EEPROM.h>
#include "Controller.h"
#include "Config.h"
#include "programs.h"
#include "Gaussian.h"

Controller::Controller() {
	matrix = new Adafruit_WS2801(MATRIX_WIDTH, MATRIX_HEIGHT, LED_MATRIX_DAT_PIN, LED_MATRIX_CLK_PIN, WS2801_RGB);
	frameRenderer = new FrameRenderer(matrix);
	// hope we do not get in trouble if initial value is not in enum range
	frameRenderer->setRotation((rotation_t) eeprom_read_byte(EEPROM_ROTATION_ADDR));

	reset();

	init_programs();
	configureProgram();
}

void Controller::setup() {
	matrix->begin();
}

void Controller::loop() {
	unsigned long loop_start = millis();

#ifdef _DEBUG
	Serial.print("@");
	Serial.print(loop_start);
#endif

	if (random_timer > 0) {
		random_timer--;
		if (random_timer == 0) {
			randomProgram();
		}
	}

	float beat_percentage = 1.0;

	if (mode == BPM) {
		uint32_t last_beat_elapsed = loop_start - last_beat_time;
		if (last_beat_elapsed > beat_interval) {
			beat_count++;
			beat_percentage = 0.0;
			// calculate when beat actually should have happened
			last_beat_time = last_beat_time + beat_interval;
			// check if we missed some beats
			if (last_beat_time < loop_start) {
				last_beat_time = loop_start;
			}
		}
		else
		{
			beat_percentage = (float)last_beat_elapsed / (float)beat_interval;
		}
	}

	if (last_beat_count != beat_count) {
		last_beat_count = beat_count;
#ifdef _DEBUG
		Serial.print("+");
		Serial.print(beat_count);
		Serial.print("p");
		Serial.print(prog);
#endif
		player->beat();
		beatLedOn = !beatLedOn;
	}

	byte* frame = player->getFrame(beat_percentage);
	if (frame == NULL) {
		// program tells us that it is done
		toggleProgram();
		loop();
		return;
	}

	frameRenderer->render(frame);

	// overflow of substraction will correctly take care of timer overflow
	// after approximately 50 days - it's a miracle!
	unsigned long loop_duration = millis() - loop_start;
	long frame_delay = traget_frame_duration_millis - loop_duration;
	if (frame_delay > 0) {
		delay(frame_delay);
	}
#ifdef _DEBUG
	Serial.print("d");
	Serial.println(frame_delay);
#endif
}

void Controller::soundTrigger() {
	// we use volatile variables to communicate between ISR and main loop
	if (mode == STL)
		beat_count++;
}

void Controller::setSpeed(uint16_t bpm) {
	beat_interval = 60000 / bpm;
}

void Controller::toggleMode() {
	uint8_t m = mode + 1;
	if (m == INV)
		m = 0;
	mode = m;

	modeLedOn = mode == STL;
}

void Controller::toggleProgram() {
	uint8_t c = sizeof(programs) / sizeof(program_data_t);

	uint8_t p = prog + 1;
	if (p >= c)
		// never return to welcome program
		p = 1;
	prog = p;

	configureProgram();

	random_timer = 0;
}

void Controller::randomProgram() {
	uint8_t c = sizeof(programs) / sizeof(program_data_t);
	long p = random(1, c);
	prog = p;

#ifdef _DEBUG
	Serial.print("z");
	Serial.println(prog);
#endif

	configureProgram();

	// schedule next randomProgram call with a normal (gaussian) distribution
	Gaussian g = Gaussian(0, 30);
	double val = g.random();
	random_timer = (int)round(val - g.mean + 10 * target_fps);
	random_timer = constrain(random_timer, 1, 20 * target_fps);
}

void Controller::rotate() {
	uint8_t r = eeprom_read_byte(EEPROM_ROTATION_ADDR);
	r++;
	if (r >= R360)
		r = R0;
	eeprom_write_byte(EEPROM_ROTATION_ADDR, r);

	frameRenderer->setRotation((rotation_t)r);

	reset();
	configureProgram();
}


void Controller::reset() {
	beat_count = 0;
	mode = BPM;
	prog = 0;
	beat_interval = 500; // 120 bpm = 2 bps = 500 ms
	beatLedOn = LOW;
	random_timer = 0;
}

void Controller::configureProgram() {
	player = programs[prog].player;
	player->configure(programs[prog].data);
}
