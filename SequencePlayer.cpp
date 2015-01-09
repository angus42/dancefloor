#include "SequencePlayer.h"

SequencePlayer::SequencePlayer(Adafruit_WS2801* m, sequence4_t* s, uint8_t fc) {
	matrix = m;
	sequence = s;
	frameCount = fc;
	currentFrame = 0;
}

void SequencePlayer::nextFrame() {
	currentFrame++;
	if (currentFrame >= frameCount)
		currentFrame = 0;
}

void SequencePlayer::showFrame() {
#ifdef _DEBUG
	unsigned long startMicros = micros();
#endif

	int i;
	for (i = 0; i < matrix->numPixels(); i++) {
		uint32_t c = color(
			(*sequence)[currentFrame][i][0],
			(*sequence)[currentFrame][i][1],
			(*sequence)[currentFrame][i][2]);
		matrix->setPixelColor(i, c);
		// Serial.print("#");
		// Serial.print(c);
	}
	matrix->show();

#ifdef _DEBUG
	unsigned long endMicros = micros();
	Serial.print("%");
	Serial.println(endMicros - startMicros);
#endif
}

// Create a 24 bit color value from R,G,B
uint32_t SequencePlayer::color(byte r, byte g, byte b)
{
	uint32_t c;
	c = r;
	c <<= 8;
	c |= g;
	c <<= 8;
	c |= b;
	return c;
}


