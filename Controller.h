// Controller.h

#ifndef _CONTROLLER_h
#define _CONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Adafruit_WS2801.h"
#include "FrameRenderer.h"
#include "SequencePlayer.h"

class Controller
{
 public:
	Controller();

	void setup();
	void loop();

	void soundTrigger();
	void setSpeed(uint16_t bpm);
	void toggleMode();
	void toggleProgram();

	bool beatLedOn;

 private:
	Adafruit_WS2801* matrix;
	FrameRenderer* frameRenderer;
	SequencePlayer* sequencePlayer;

	volatile uint8_t mode;
	volatile uint8_t prog;
	volatile uint16_t beat_interval; // just enouth for 1 bpm in milliseconds
	volatile uint16_t beat_count;
	uint16_t last_beat_count;
};

#endif

