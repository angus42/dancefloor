#include <SPI.h>
#include "Adafruit_WS2801.h"

volatile int intCount = 0;
volatile bool ledOn = LOW;
unsigned long lastIntMillis;

const int stripSize = 25;

uint8_t ledPin = 13;
uint8_t soundSensorInt = 0; // pin 2
uint8_t ledStripDataPin = 4;
uint8_t ledStripClockPin = 5;
Adafruit_WS2801 strip = Adafruit_WS2801(stripSize, ledStripDataPin, ledStripClockPin);

void setup() {
	pinMode(ledPin, OUTPUT);
	attachInterrupt(soundSensorInt, soundTrigger, FALLING);
	Serial.begin(38400);
}

void loop() {
	digitalWrite(ledPin, ledOn);
	Serial.println(intCount);

	unsigned long startMicros = micros();
	colorWipe(Color(255, 0, 0));
	unsigned long endMicros = micros();
	Serial.print("#");
	Serial.println(endMicros - startMicros);

	colorWipe(Color(0, 255, 0));
	colorWipe(Color(0, 0, 255));
}

void soundTrigger()
{
	unsigned long currentMillis = millis();
	if ((currentMillis - lastIntMillis) >= 200)
	{
		ledOn = !ledOn;
		intCount++;
		lastIntMillis = currentMillis;
	}
}

// fill the dots one after the other with said color
// good for testing purposes
void colorWipe(uint32_t c) {
	int i;
	for (i = 0; i < strip.numPixels(); i++) {
		strip.setPixelColor(i, c);
	}
	strip.show();
}

// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
	uint32_t c;
	c = r;
	c <<= 8;
	c |= g;
	c <<= 8;
	c |= b;
	return c;
}