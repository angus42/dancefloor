// PlasmaPlayer.h

#ifndef _PLASMAPLAYER_h
#define _PLASMAPLAYER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Config.h"
#include "Player.h"

class PlasmaPlayer : public Player
{
public:
	PlasmaPlayer();

	virtual void configure(void* d);
	virtual void beat();
	virtual byte* getFrame(float beat_percentage);

private:
	int frame_count;
	int beat_frame_count;
	float bps;

	double plasma(float x, float y, float time);
	void colorMap(uint8_t x, uint8_t y, double v);
};

const double plasma_period = 12.0 * PI;

extern PlasmaPlayer plasmaPlayer;

#endif
