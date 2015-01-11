#include "Controller.h"
#include "Config.h"
#include "sequences.h"

Controller::Controller() {
	matrix = new Adafruit_WS2801(matrixWidth, matrixHeight, ledMatrixDataPin, ledMatrixClockPin, WS2801_RGB);
	frameRenderer = new FrameRenderer(matrix);
	sequencePlayer = new SequencePlayer();

	beat_count = 0;
	beatLedOn = LOW;
}

void Controller::setup() {
	sequencePlayer->configure(&sequences[0]);

	matrix->begin();
}

void Controller::loop() {
	unsigned long loop_start = millis();

	if (last_beat_count != beat_count) {
		last_beat_count = beat_count;
		sequencePlayer->moveNextFrame();
		beatLedOn = !beatLedOn;

#ifdef _DEBUG
		Serial.print("+");
		Serial.println(beat_count);
#endif
	}

	byte* frame = sequencePlayer->getCurrentFrame();
	frameRenderer->render(frame);

	// overflow of substraction will correctly take care of timer overflow
	// after approximately 50 days - it's a miracle!
	unsigned long loop_duration = millis() - loop_start;
	unsigned long frame_delay = traget_frame_duration_millis - loop_duration;
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
	// if (mode == STL)
		beat_count++;
}

void Controller::setSpeed(uint16_t bpm) {
	//
}

void Controller::toggleMode() {
	//
}

void Controller::toggleProgram() {
	//
}