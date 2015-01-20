#include <SPI.h>
#include "Controller.h"
#include "Config.h"
#include "fscale.h"
#include "MemoryFree.h"

unsigned long lastSoundTriggerMillis;
unsigned long lastButtonDownMillis;
uint16_t lastSpeedPotiValue;
uint8_t lastProgToggleButtonValue;
uint8_t lastModeToggleButtonValue;
bool waitKeysUp;

Controller controller;

void setup() {
	Serial.begin(115200);

	pinMode(BEAT_LED_PIN, OUTPUT);
	pinMode(MODE_LED_PIN, OUTPUT);
	pinMode(PROG_TOGGLE_BUTTON_PIN, INPUT);
	pinMode(MODE_TOGGLE_BUTTON_PIN, INPUT);
	attachInterrupt(SOUND_SENSOR_INT, soundTrigger, FALLING);

	controller.setup();

#ifdef _DEBUG
	Serial.print(F("free memory: "));
	Serial.println(freeMemory());
#endif
}

void loop() {
	// check for commands from serial port
	if (Serial.available() > 0) {
		char serial_char = Serial.read();
		switch (serial_char) {
		case 'p': controller.toggleProgram(); break;
		case 'z': controller.randomProgram(); break;
		case 'm': controller.toggleMode(); break;
		case 'r': controller.rotate(); break;
		}
	}

#ifndef _NO_HARDWARE
	uint16_t speedPotiValue = analogRead(SPEED_POTI_PIN);
	if (speedPotiValue != lastSpeedPotiValue) {
		uint16_t bpm;
		bpm = fscale(0, 1023, min_bpm, max_bpm, speedPotiValue, 0);
		controller.setSpeed(bpm);
	}

	// buttons should be active high so a long press works as expected

	uint8_t progToggleButtonValue = digitalRead(PROG_TOGGLE_BUTTON_PIN);
	uint8_t modeToggleButtonValue = digitalRead(MODE_TOGGLE_BUTTON_PIN);

	if ((progToggleButtonValue == HIGH) || (modeToggleButtonValue == HIGH)) {
		unsigned long currentMillis = millis();

		if (progToggleButtonValue == HIGH) {
			if (lastProgToggleButtonValue == LOW) {
				lastButtonDownMillis = currentMillis;
				controller.toggleProgram();
			}
			// waitKeysUp will prevent this code from beeing triggert multiple times after the first buttonDownMillis have elapsed
			else if (!waitKeysUp && ((currentMillis - lastButtonDownMillis) > buttonDownMillis)) {
				waitKeysUp = true;
				if (modeToggleButtonValue == HIGH) {
					controller.rotate();
				}
				else {
					randomSeed(micros());
					controller.randomProgram();
				}
			}
		}

		if (modeToggleButtonValue == HIGH) {
			if (lastModeToggleButtonValue == LOW) {
				lastButtonDownMillis = currentMillis;
				controller.toggleMode();
			}
		}
	}
	else {
		waitKeysUp = false;
	}


	lastModeToggleButtonValue = modeToggleButtonValue;
	lastProgToggleButtonValue = progToggleButtonValue;
#endif

	controller.loop();

	digitalWrite(BEAT_LED_PIN, controller.beatLedOn);
	digitalWrite(MODE_LED_PIN, controller.modeLedOn);
}

void soundTrigger() {
	unsigned long currentMillis = millis();
	if ((currentMillis - lastSoundTriggerMillis) >= minSoundTriggerMillis)
	{
		controller.soundTrigger();
		lastSoundTriggerMillis = currentMillis;
	}
}
