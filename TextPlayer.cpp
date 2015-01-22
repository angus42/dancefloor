#include <avr/EEPROM.h>
#include "Alphabet.h"
#include "Config.h"
#include "TextPlayer.h"

TextPlayer::TextPlayer() {
}

void TextPlayer::configure(void* d) {
	index = 0;
	offset = 0;	
}

void TextPlayer::beat() {
	offset++;
	if (offset > MATRIX_WIDTH) { // should be CHAR_WIDTH
		offset = 0;
		index++;
		if (eeprom_read_byte((uint8_t*)EEPROM_TEXT_MESSAGE_ADDR + index) == 0x00)
			index = 0;
	}

//#ifdef _DEBUG
//	char c = eeprom_read_byte((uint8_t*)EEPROM_TEXT_MESSAGE_ADDR + index);
//	Serial.println();
//	Serial.print(c);
//	Serial.print("-");
//	Serial.print(offset);
//	Serial.println();
//#endif
}

byte* TextPlayer::getFrame(float beat_percentage) {
	byte o = offset;
	byte i = index;
	for (byte x = 0; x < MATRIX_WIDTH; x++) {
		byte stripe = 0;
		if (o < MATRIX_WIDTH)
		{
			char c = eeprom_read_byte((uint8_t*)EEPROM_TEXT_MESSAGE_ADDR + i);
			// Windows-1252 / ISO-8859-1
			// 0x60 ` = Ä => 0xC4
			// 0x61 a = Ö => 0xD6
			// 0x62 b = Ü => 0xDC
			// 0x63 c = []
			if (c < 0x20)
				c = 0x63;
			else if (c == 0xC4)
				c = 0x60;
			else if (c == 0xD6)
				c = 0x61;
			else if (c == 0xDC)
				c = 0x62;
			else if (c >= 0x60)
				c = 0x63;

			stripe = pgm_read_byte(&alphabet[(c - 0x20)][o]); // should be CHAR_WIDTH
		}
		for (byte y = 0; y < MATRIX_HEIGHT; y++) {
			short p = x + y * MATRIX_WIDTH;
			bool pixel = stripe & (1 << y);
			byte color = pixel ? 0xff : 0x00;
			shared_frame[p][0] = color;
			shared_frame[p][1] = color;
			shared_frame[p][2] = color;
		}

		// same as beat() but frame local
		o++;
		if (o > MATRIX_WIDTH) { // should be CHAR_WIDTH
			o = 0;
			i++;
			if (eeprom_read_byte((uint8_t*)EEPROM_TEXT_MESSAGE_ADDR + i) == 0x00)
				i = 0;
		}
	}
	return (byte*)shared_frame;
}

TextPlayer textPlayer;
