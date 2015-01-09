// Config.h

#ifndef _CONFIG_h
#define _CONFIG_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

const uint8_t matrixWidth = 5;
const uint8_t matrixHeight = 5;

const uint16_t minSoundTriggerMillis = 200;

const uint8_t ledPin = 13;
const uint8_t soundSensorInt = 0; // pin 2
const uint8_t ledMatrixDataPin = 4;
const uint8_t ledMatrixClockPin = 5;

typedef byte frame_t[matrixWidth * matrixHeight][3];
typedef frame_t sequence4_t[4];
typedef frame_t sequence_t[];

#endif

