// Config.h

#ifndef _CONFIG_h
#define _CONFIG_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Player.h"

// led matrix size
#define MATRIX_WIDTH 5
#define MATRIX_HEIGHT 5

// eeprom addresses for storing configuration
#define EEPROM_ROTATION_ADDR 0
#define EEPROM_TEXT_MESSAGE_ADDR 100
#define EEPROM_TEXT_MESSAGE_SIZE 144

// I/O
//////

#define BEAT_LED_PIN 13
#define SPEED_POTI_PIN A0
#define RANDOM_SEED_PIN A4
#define PROG_TOGGLE_BUTTON_PIN 6
#define MODE_TOGGLE_BUTTON_PIN 7
#define MODE_LED_PIN 8
// Int0 is on pin 2
#define SOUND_SENSOR_INT 0
#define LED_MATRIX_DAT_PIN 4
#define LED_MATRIX_CLK_PIN 5

// we keep these consts the in RAM (not PROGMEM) for fast access

// timing
/////////

const uint8_t target_fps = 60;
const uint16_t traget_frame_duration_millis = 1000 / target_fps;

const uint16_t minSoundTriggerMillis = 200;
const uint16_t buttonDownMillis = 1000;

const uint16_t min_bpm = 1; // this is realy slow
const uint16_t max_bpm = 1800; // we hardcode this, so scaling stays the same if we change target_fps (1800 =^ 30 fps)


// basic types
//////////////

typedef enum rotation {
	R0 = 0,
	R90 = 1,
	R180 = 2,
	R270 = 3,
	R360 = 4
} rotation_t;

typedef byte frame_t[MATRIX_WIDTH * MATRIX_HEIGHT][3];

typedef byte palette_frame_t[MATRIX_WIDTH * MATRIX_HEIGHT];

typedef frame_t sequence_t[];

typedef palette_frame_t palette_sequence_t[];

typedef byte color_palette_t[][3];

static frame_t shared_frame;

typedef struct program_data {
	Player *player;
	void *data;
} program_data_t;

typedef struct sequence_data {
	byte *sequence;
	byte frame_count;
} sequence_data_t;

typedef struct palette_sequence_data {
	byte *sequence;
	byte frame_count;
	byte *color_palette;
	bool xfade;
} palette_sequence_data_t;

typedef struct text_data {
	char* message;
	byte length;
	bool scroll;
} text_data_t;

#endif

