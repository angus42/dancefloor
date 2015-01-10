// FrameRenderer.h

#ifndef _FRAMERENDERER_h
#define _FRAMERENDERER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Config.h"
#include "Adafruit_WS2801.h"

class FrameRenderer
{
 public:
	FrameRenderer(Adafruit_WS2801* m);
	void render(byte* frame);

protected:
	uint32_t color(byte r, byte g, byte b);

private:
	Adafruit_WS2801* matrix;
};

#endif

