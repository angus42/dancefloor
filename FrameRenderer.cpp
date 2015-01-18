#include "FrameRenderer.h"

FrameRenderer::FrameRenderer(Adafruit_WS2801* m) {
	matrix = m;
}

void FrameRenderer::render(byte* frame) {
#ifdef _DEBUG
	unsigned long startMicros = micros();
#endif

	int i;
	for (i = 0; i < matrix->numPixels(); i++) {
		uint32_t c = color(
			*(frame + i * 3 + 2),
			*(frame + i * 3 + 1),
			*(frame + i * 3));
		matrix->setPixelColor(i, c);
#if defined(_DEBUG) && defined(_NO_HARDWARE)
		Serial.print("#");
		Serial.print(c, HEX);
#endif
	}
	matrix->show();

#ifdef _DEBUG
	unsigned long endMicros = micros();
	Serial.print("r");
	Serial.print(endMicros - startMicros);
#endif
}

// Create a 24 bit color value from R,G,B
uint32_t FrameRenderer::color(byte r, byte g, byte b)
{
	uint32_t c;
	c = r;
	c <<= 8;
	c |= g;
	c <<= 8;
	c |= b;
	return c;
}




