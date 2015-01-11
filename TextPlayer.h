// TextPlayer.h

#ifndef _TEXTPLAYER_h
#define _TEXTPLAYER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Config.h"

class TextPlayer
{
public:
	TextPlayer();

	void configure(void* d);
	void moveNextFrame();
	byte* getCurrentFrame();

private:
};

#endif

