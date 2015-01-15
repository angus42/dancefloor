#include <SPI.h>
#include "Controller.h"
#include "Config.h"
#include "fscale.h"
#include "MemoryFree.h"

unsigned long lastSoundTriggerMillis;
unsigned long lastProgToggleButtonDownMillis;
int lastSpeedPotiValue;
int lastProgToggleButtonValue;
int lastModeToggleButtonValue;

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
		if (serial_char == 'p') {
			controller.toggleProgram();
		}
		if (serial_char == 'r') {
			controller.randomProgram();
		}
		if (serial_char == 'm') {
			controller.toggleMode();
		}
	}

#ifndef _NO_HARDWARE
	int speedPotiValue = analogRead(SPEED_POTI_PIN);
	if (speedPotiValue != lastSpeedPotiValue) {
		uint16_t bpm;
		bpm = fscale(0, 1023, min_bpm, max_bpm, speedPotiValue, 0);
		controller.setSpeed(bpm);
	}

	// buttons should be active high so a long press works as expected

	int progToggleButtonValue = digitalRead(PROG_TOGGLE_BUTTON_PIN);
	if (progToggleButtonValue == HIGH) {
		if (lastProgToggleButtonValue == LOW) {
			controller.toggleProgram();
			lastProgToggleButtonDownMillis = millis();
		}
		else if ((millis() - lastProgToggleButtonDownMillis) > buttonDownMillis) {
			randomSeed(micros());
			controller.randomProgram();
			lastProgToggleButtonDownMillis = millis();
		}
	}
	lastProgToggleButtonValue = progToggleButtonValue;

	int modeToggleButtonValue = digitalRead(MODE_TOGGLE_BUTTON_PIN);
	if (modeToggleButtonValue == HIGH) {
		if (lastModeToggleButtonValue == LOW) {
			controller.toggleMode();
		}
	}
	lastModeToggleButtonValue = modeToggleButtonValue;
#endif

	controller.loop();

	digitalWrite(BEAT_LED_PIN, controller.beatLedOn);
	digitalWrite(MODE_LED_PIN, controller.modeLedOn);
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
