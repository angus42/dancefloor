// TextPlayer.h

#ifndef _TEXTPLAYER_h
#define _TEXTPLAYER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Player.h"

class TextPlayer : public Player
{
public:
	TextPlayer();

	virtual void configure(void* d);
	virtual void beat();
	virtual byte* getFrame(float beat_percentage);

private:
};

#endif

