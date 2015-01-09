// SequencePlayer.h

#ifndef _SEQUENCEPLAYER_h
#define _SEQUENCEPLAYER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif
#include "Config.h"
#include "Adafruit_WS2801.h"

class SequencePlayer
{
 public:
	 SequencePlayer(Adafruit_WS2801* m, byte* s, uint8_t fc);

	 void nextFrame();
	 void showFrame();

 protected:
	 uint32_t color(byte r, byte g, byte b);

 private:
	 Adafruit_WS2801* matrix;
	 byte* sequence;
	 uint8_t frameCount;
	 uint8_t currentFrame;
};

#endif

