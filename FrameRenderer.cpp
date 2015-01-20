#include "FrameRenderer.h"

FrameRenderer::FrameRenderer(Adafruit_WS2801* m) {
	matrix = m;
}

void FrameRenderer::render(byte* frame) {
#ifdef _DEBUG
	unsigned long startMicros = micros();
#endif

	for (int y = 0; y < MATRIX_HEIGHT; y++) {
		for (int x = 0; x < MATRIX_WIDTH; x++) {
			uint16_t o;
			switch (rotation) {
			case R90:
				o = y + (MATRIX_WIDTH - x - 1) * MATRIX_WIDTH;
				break;
			case R180:
				o = (MATRIX_WIDTH - x - 1) + (MATRIX_HEIGHT - y - 1) * MATRIX_WIDTH;
				break;
			case R270:
				o = (MATRIX_HEIGHT - y - 1) + x * MATRIX_WIDTH;
				break;
			case R0:
			default:
				o = x + y * MATRIX_WIDTH;
				break;
			}
			o *= 3;
			uint32_t c = color(
				*(frame + o + 2),
				*(frame + o + 1),
				*(frame + o));
			matrix->setPixelColor(x + y * MATRIX_WIDTH, c);

#if defined(_DEBUG) && defined(_NO_HARDWARE)
			Serial.print("#");
			Serial.print(c, HEX);
#endif
		}
	}
	matrix->show();

#ifdef _DEBUG
	unsigned long endMicros = micros();
	Serial.print("t");
	Serial.print(endMicros - startMicros);
#endif
}

void FrameRenderer::setRotation(rotation_t r) {
	rotation = r;
}

// Create a 24 bit color value from R,G,B
uint32_t FrameRenderer::color(byte r, byte g, byte b) {
	uint32_t c;
	c = r;
	c <<= 8;
	c |= g;
	c <<= 8;
	c |= b;
	return c;
}
