#include "TextPlayer.h"
#include <SPI.h>

#include "Controller.h"
#include "Config.h"
#include "fscale.h"

unsigned long lastSoundTriggerMillis;
int lastSpeedPotiValue;

Controller controller;

void setup() {
	Serial.begin(115200);

	pinMode(beatLedPin, OUTPUT);
	attachInterrupt(soundSensorInt, soundTrigger, FALLING);

	controller.setup();

	controller.setSpeed(120);
//	uint16_t bpm;
//	bpm = fscale(0, 1023, min_bpm, max_bpm, speedPotiValue, 0);
}

void loop() {
	int speedPotiValue = analogRead(speedPotiPin);
	if (speedPotiValue != lastSpeedPotiValue) {
		uint16_t bpm;
		bpm = fscale(0, 1023, min_bpm, max_bpm, speedPotiValue, 0);
		controller.setSpeed(bpm);
	}
	// TODO: mode and prog buttons

	controller.loop();

	digitalWrite(beatLedPin, controller.beatLedOn);
	// TODO: mode led
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
