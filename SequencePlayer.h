// SequencePlayer.h

#ifndef _SEQUENCEPLAYER_h
#define _SEQUENCEPLAYER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Config.h"

class SequencePlayer
{
 public:
	 SequencePlayer();

	 void configure(void* d);
	 void moveNextFrame();
	 byte* getCurrentFrame();

 private:
	 sequence_data_t* data;
	 uint8_t currentFrameIndex;
};

#endif

