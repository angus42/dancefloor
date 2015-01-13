// SequencePlayer.h

#ifndef _SEQUENCEPLAYER_h
#define _SEQUENCEPLAYER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Player.h"
#include "Config.h"

class SequencePlayer : public Player
{
 public:
	 SequencePlayer();

	 virtual void configure(void* d);
	 virtual void beat();
	 virtual byte* getFrame();

 private:
	 sequence_data_t* data;
	 uint8_t currentFrameIndex;
};

extern SequencePlayer sequencePlayer;

#endif

