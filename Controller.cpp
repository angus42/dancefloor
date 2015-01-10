#include "Controller.h"
#include "Config.h"
#include "sequences.h"

Controller::Controller() {
	matrix = new Adafruit_WS2801(matrixWidth, matrixHeight, ledMatrixDataPin, ledMatrixClockPin, WS2801_RGB);
	frameRenderer = new FrameRenderer(matrix);
	sequencePlayer = new SequencePlayer();

	intCount = 0;
	ledOn = LOW;
}

void Controller::setup() {
	sequencePlayer->configure(&sequences[0]);

	matrix->begin();
}

void Controller::loop() {
	if (lastIntCount != intCount) {
		sequencePlayer->moveNextFrame();
		lastIntCount = intCount;
#ifdef _DEBUG
		Serial.print("+");
		Serial.println(intCount);
#endif
	}

	byte* frame = sequencePlayer->getCurrentFrame();
	frameRenderer->render(frame);

	digitalWrite(ledPin, ledOn);
	delay(50);
}

void Controller::soundTrigger() {
	ledOn = !ledOn;
	intCount++;
}

/*
void Controller::setSpeed(int value) {
	//
}

void Controller::toggleSoundToLight() {
	//
}

void Controller::toggleProgram() {
	//
}

void Controller::randomProgramMode() {
	//
}
*/