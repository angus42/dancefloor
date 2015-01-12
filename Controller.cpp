#include "Controller.h"
#include "Config.h"
#include "programs.h"

Controller::Controller() {
	matrix = new Adafruit_WS2801(matrixWidth, matrixHeight, ledMatrixDataPin, ledMatrixClockPin, WS2801_RGB);
	frameRenderer = new FrameRenderer(matrix);

	beat_count = 0;
	mode = BPM;
	prog = 0;
	beat_interval = 500; // 120 bpm = 2 bps = 500 ms
	beatLedOn = LOW;

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

	if (mode == BPM) {
		if ((loop_start - last_beat_time) > beat_interval) {
			beat_count++;
			// calculate when beat actually should have happened
			last_beat_time = last_beat_time + beat_interval;
			// check if we missed some beats
			if (last_beat_time < loop_start) {
				last_beat_time = loop_start;
			}
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

	byte* frame = player->getFrame();
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
	uint8_t p = prog + 1;
	uint8_t c = sizeof(programs) / sizeof(program_data_t);
	if (p >= c)
		// never return to welcome program
		p = 1;
	prog = p;

	configureProgram();
}

void Controller::configureProgram() {
	player = programs[prog].player;
	player->configure(programs[prog].data);
}
