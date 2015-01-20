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
	void setRotation(rotation_t r);

protected:
	uint32_t color(byte r, byte g, byte b);
	rotation_t rotation;

private:
	Adafruit_WS2801* matrix;
};

#endif

