// Config.h

#ifndef _CONFIG_h
#define _CONFIG_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

// led matrix size

const uint8_t matrixWidth = 5;
const uint8_t matrixHeight = 5;

// I/O

const uint8_t ledPin = 13;
const uint8_t soundSensorInt = 0; // pin 2
const uint8_t ledMatrixDataPin = 4;
const uint8_t ledMatrixClockPin = 5;

// timing

const uint8_t target_fps = 30;
const uint16_t traget_frame_duration_millis = 1000 / target_fps;

const uint16_t minSoundTriggerMillis = 200;

// basic types

typedef byte frame_t[matrixWidth * matrixHeight][3];

typedef frame_t sequence_t[];
typedef struct sequence_data {
	byte *sequence;
	byte frame_count;
} sequence_data_t;

#endif

