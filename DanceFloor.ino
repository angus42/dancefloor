#include <SPI.h>
#include "Controller.h"
#include "Config.h"
#include "fscale.h"

unsigned long lastSoundTriggerMillis;
int lastSpeedPotiValue;
int lastProgToggleButtonValue;
int lastModeToggleButtonValue;

Controller controller;

void setup() {
	Serial.begin(115200);

	pinMode(beatLedPin, OUTPUT);
	pinMode(modeLedPin, OUTPUT);
	pinMode(progToggleButtonPin, INPUT);
	pinMode(modeToggleButtonPin, INPUT);
	attachInterrupt(soundSensorInt, soundTrigger, FALLING);

	controller.setup();
}

void loop() {
	// check for commands from serial port
	if (Serial.available() > 0) {
		char serial_char = Serial.read();
		if (serial_char == 'p') {
			controller.toggleProgram();
		}
		if (serial_char == 'm') {
			controller.toggleMode();
		}
	}

	int speedPotiValue = analogRead(speedPotiPin);
	if (speedPotiValue != lastSpeedPotiValue) {
		uint16_t bpm;
		bpm = fscale(0, 1023, min_bpm, max_bpm, speedPotiValue, 0);
		controller.setSpeed(bpm);
	}

	int progToggleButtonValue = digitalRead(progToggleButtonPin);
	if (lastProgToggleButtonValue == LOW && progToggleButtonValue == HIGH) {
		controller.toggleProgram();
	}
	lastProgToggleButtonValue = progToggleButtonValue;

	int modeToggleButtonValue = digitalRead(modeToggleButtonPin);
	if (lastModeToggleButtonValue == LOW && modeToggleButtonValue == HIGH) {
		controller.toggleMode();
	}
	lastModeToggleButtonValue = modeToggleButtonValue;

	controller.loop();

	digitalWrite(beatLedPin, controller.beatLedOn);
	digitalWrite(modeLedPin, controller.modeLedOn);
}

void soundTrigger()
{
	unsigned long currentMillis = millis();
	if ((currentMillis - lastSoundTriggerMillis) >= minSoundTriggerMillis)
	{
		controller.soundTrigger();
		lastSoundTriggerMillis = currentMillis;
	}
}
