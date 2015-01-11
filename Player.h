// Player.h

#ifndef _PLAYER_h
#define _PLAYER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class Player
{
 public:
	virtual void configure(void* d) = 0;
	virtual void beat() = 0;
	virtual byte* getFrame() = 0;

 private:
};

#endif

