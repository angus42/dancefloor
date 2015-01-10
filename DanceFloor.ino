#include <SPI.h>

#include "Controller.h"
#include "Config.h"

unsigned long lastIntMillis;

Controller controller;

void setup() {
	Serial.begin(115200);

	pinMode(ledPin, OUTPUT);
	attachInterrupt(soundSensorInt, soundTrigger, FALLING);

	controller.setup();
}

void loop() {
	controller.loop();
}

void soundTrigger()
{
	unsigned long currentMillis = millis();
	if ((currentMillis - lastIntMillis) >= minSoundTriggerMillis)
	{
		controller.soundTrigger();
		lastIntMillis = currentMillis;
	}
}
