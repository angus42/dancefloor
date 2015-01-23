#include <avr/EEPROM.h>
#include "Alphabet.h"
#include "Config.h"
#include "TextPlayer.h"

TextPlayer::TextPlayer() {
}

void TextPlayer::configure(void* d) {
	index = 0;
	offset = 0;
	message = (char*) d;
}

void TextPlayer::beat() {
	offset++;
	if (offset > MATRIX_WIDTH) { // should be CHAR_WIDTH
		offset = 0;
		index++;
		if (read(index) == 0x00) {
			if (message != NULL)
				index = 255;
			else
				index = 0;
		}
	}

#ifdef _DEBUG
	char c = read(index);
	Serial.println();
	Serial.print(c);
	Serial.print("-");
	Serial.print(offset);
	Serial.println();
#endif
}

byte* TextPlayer::getFrame(float beat_percentage) {
	// HACK: static messages end after one round - this is the "lex welcome text"
	if (index == 255)
		return NULL;
	byte o = offset;
	byte i = index;
	char c = read(i);
	for (byte x = 0; x < MATRIX_WIDTH; x++) {
		byte stripe = 0;
		if (o < MATRIX_WIDTH) {
			stripe = pgm_read_byte(&alphabet[(c - 0x20)][o]); // should be CHAR_WIDTH
		}
		for (byte y = 0; y < MATRIX_HEIGHT; y++) {
			short p = x + y * MATRIX_WIDTH;
			bool pixel = stripe & (1 << y);
			shared_frame[p][0] = pixel ? 63 * y : 0;
			shared_frame[p][1] = pixel ? 255 - (63 * y) : 0;
			shared_frame[p][2] = pixel ? ((i * MATRIX_WIDTH + o + x) * 2) % 256 : 15;
		}

		// same as beat() but frame local
		o++;
		if (o > MATRIX_WIDTH) { // should be CHAR_WIDTH
			o = 0;
			i++;
			c = read(i);
			if (c == 0x00) {
				i = 0;
				c = read(i);
			}				
		}
	}
	return (byte*)shared_frame;
}

char TextPlayer::read(byte i) {
	byte result = 0x00;
	if (message == NULL)
		result = eeprom_read_byte((uint8_t*)EEPROM_TEXT_MESSAGE_ADDR + i);
	else
		result = pgm_read_byte(&message[i]);

	// Windows-1252 / ISO-8859-1
	// 0x60 ` = Ä => 0xC4
	// 0x61 a = Ö => 0xD6
	// 0x62 b = Ü => 0xDC
	// 0x63 c = smiley => 0xA9 (copyright)
	// 0x64 d = []
	if (result == 0x00)
		return result;
	if (result < 0x20)
		return 0x64;
	if (result == 0xC4)
		return 0x60;
	if (result == 0xD6)
		return 0x61;
	if (result == 0xDC)
		return 0x62;
	if (result == 0xA9)
		return 0x63;
	if (result >= 0x60)
		return 0x64;
	return result;
}

TextPlayer textPlayer;
