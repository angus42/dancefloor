// PaletteSequencePlayer.h

#ifndef _PALETTESEQUENCEPLAYER_h
#define _PALETTESEQUENCEPLAYER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Player.h"
#include "Config.h"

class PaletteSequencePlayer : public Player
{
 public:
	 PaletteSequencePlayer();

	 virtual void configure(void* d);
	 virtual void beat();
	 virtual byte* getFrame();

 private:
	 palette_sequence_data_t* data;
	 uint8_t currentFrameIndex;
};

extern PaletteSequencePlayer paletteSequencePlayer;

#endif

