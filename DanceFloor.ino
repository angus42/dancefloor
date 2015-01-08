#include <SPI.h>
#include "Adafruit_WS2801.h"
#include "SequencePlayer.h"
#include "Config.h"
#include "FourColor.h"

volatile int intCount = 0;
volatile bool ledOn = LOW;
unsigned long lastIntMillis;

Adafruit_WS2801 matrix(matrixWidth, matrixHeight, ledMatrixDataPin, ledMatrixClockPin, WS2801_RGB);
SequencePlayer player(&matrix, &FourColor, 4);

void setup() {
	pinMode(ledPin, OUTPUT);
	attachInterrupt(soundSensorInt, soundTrigger, FALLING);
	// Serial.begin(38400);
	Serial.begin(115200);
}

void loop() {
	digitalWrite(ledPin, ledOn);
	Serial.println(intCount);

	player.showFrame();
	delay(100);
	player.nextFrame();
}

void soundTrigger()
{
	unsigned long currentMillis = millis();
	if ((currentMillis - lastIntMillis) >= minSoundTriggerMillis)
	{
		ledOn = !ledOn;
		intCount++;
		lastIntMillis = currentMillis;
	}
}
