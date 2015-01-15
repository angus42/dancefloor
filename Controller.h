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

const uint8_t BPM = 0; // beats per minute (speed)
const uint8_t STL = 1; // sound to light
const uint8_t INV = 2; // invalid mode - just a marker

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
	void randomProgram();

	bool beatLedOn;
	bool modeLedOn;

 private:
	Adafruit_WS2801* matrix;
	FrameRenderer* frameRenderer;
	Player* player;

	volatile uint8_t mode;
	uint8_t prog;
	uint16_t beat_interval; // just enouth for 1 bpm in milliseconds
	volatile uint16_t beat_count;
	uint16_t last_beat_count;
	unsigned long last_beat_time;
	unsigned long random_timer;

	void configureProgram();
};

#endif

