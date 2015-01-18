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
	 virtual byte* getFrame(float beat_percentage);

 private:
	 palette_sequence_data_t* data;
	 uint8_t currentFrameIndex;
	 byte* lastFrame;

	 byte lookup(uint8_t index, uint8_t component_index);
	 byte interpolate(uint8_t source_index, uint8_t target_index, float percentage, uint8_t component_index);
};

extern PaletteSequencePlayer paletteSequencePlayer;

#endif

