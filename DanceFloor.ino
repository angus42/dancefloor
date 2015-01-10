#include <SPI.h>
#include "Adafruit_WS2801.h"
#include "SequencePlayer.h"
#include "Config.h"
#include "sequences.h"

volatile int intCount = 0;
volatile bool ledOn = LOW;
unsigned long lastIntMillis;
unsigned int lastIntCount;

Adafruit_WS2801 matrix(matrixWidth, matrixHeight, ledMatrixDataPin, ledMatrixClockPin, WS2801_RGB);
SequencePlayer player(&matrix, sequences[0].sequence, sequences[0].frame_count);

void setup() {
	pinMode(ledPin, OUTPUT);
	attachInterrupt(soundSensorInt, soundTrigger, FALLING);
	matrix.begin();
	Serial.begin(115200);
}

void loop() {
	digitalWrite(ledPin, ledOn);
	player.showFrame();
	delay(50);

	if (lastIntCount != intCount) {
		player.nextFrame();
		lastIntCount = intCount;
#ifdef _DEBUG
		Serial.print("+");
		Serial.println(intCount);
#endif
	}
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
