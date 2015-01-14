// Config.h

#ifndef _CONFIG_h
#define _CONFIG_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Player.h"

// we keep all consts the in RAM (not PROGMEM) for fast access

// led matrix size
const uint8_t matrixWidth = 5;
const uint8_t matrixHeight = 5;

// I/O
//////

const uint8_t beatLedPin          = 13;
const uint8_t speedPotiPin        = A0;
const uint8_t progToggleButtonPin = 6;
const uint8_t modeToggleButtonPin = 7;
const uint8_t modeLedPin          = 8;
const uint8_t soundSensorInt      = 0; // pin 2
const uint8_t ledMatrixDataPin    = 4;
const uint8_t ledMatrixClockPin   = 5;

// timing
/////////

const uint8_t target_fps = 60;
const uint16_t traget_frame_duration_millis = 1000 / target_fps;

const uint16_t minSoundTriggerMillis = 200;

const uint16_t min_bpm = 1; // this is realy slow
const uint16_t max_bpm = 1800; // we hardcode this, so scaling stays the same if we change target_fps (1800 =^ 30 fps)

// basic types
//////////////

typedef byte frame_t[matrixWidth * matrixHeight][3];

typedef frame_t sequence_t[];

static frame_t shared_frame;

typedef struct program_data {
	Player *player;
	void *data;
} program_data_t;

typedef struct sequence_data {
	byte *sequence;
	byte frame_count;
} sequence_data_t;

typedef struct text_data {
	char* message;
	byte length;
	bool scroll;
} text_data_t;

#endif

