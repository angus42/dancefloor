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

 private:
	 Adafruit_WS2801* matrix;
	 FrameRenderer* frameRenderer;
	 SequencePlayer* sequencePlayer;

	 volatile int intCount;
	 volatile bool ledOn;
	 unsigned int lastIntCount;
};

#endif

