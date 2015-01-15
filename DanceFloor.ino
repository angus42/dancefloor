#include <SPI.h>
#include "Controller.h"
#include "Config.h"
#include "fscale.h"
#include "MemoryFree.h"

unsigned long lastSoundTriggerMillis;
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
		if (serial_char == 'm') {
			controller.toggleMode();
		}
	}

	int speedPotiValue = analogRead(SPEED_POTI_PIN);
	if (speedPotiValue != lastSpeedPotiValue) {
		uint16_t bpm;
		bpm = fscale(0, 1023, min_bpm, max_bpm, speedPotiValue, 0);
#ifndef _NO_HARDWARE
		controller.setSpeed(bpm);
#endif
	}

	int progToggleButtonValue = digitalRead(PROG_TOGGLE_BUTTON_PIN);
	if (lastProgToggleButtonValue == LOW && progToggleButtonValue == HIGH) {
#ifndef _NO_HARDWARE
		controller.toggleProgram();
#endif
	}
	lastProgToggleButtonValue = progToggleButtonValue;

	int modeToggleButtonValue = digitalRead(MODE_TOGGLE_BUTTON_PIN);
	if (lastModeToggleButtonValue == LOW && modeToggleButtonValue == HIGH) {
#ifndef _NO_HARDWARE
		controller.toggleMode();
#endif
	}
	lastModeToggleButtonValue = modeToggleButtonValue;

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
