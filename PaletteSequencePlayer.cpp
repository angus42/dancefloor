#include <avr/pgmspace.h>
#include "PaletteSequencePlayer.h"

PaletteSequencePlayer::PaletteSequencePlayer() {
}

void PaletteSequencePlayer::configure(void* d) {
	data = (palette_sequence_data_t*)d;
	currentFrameIndex = 0;
}

void PaletteSequencePlayer::beat() {
	currentFrameIndex++;
	if (currentFrameIndex >= data->frame_count)
		currentFrameIndex = 0;

#ifdef _DEBUG
	Serial.print("f");
	Serial.print(currentFrameIndex);
#endif
}

byte* PaletteSequencePlayer::getFrame() {
	if (data->sequence == NULL)
		return NULL;

	int fs = sizeof(palette_frame_t);
	for (int y = 0; y < MATRIX_HEIGHT; y++) {
		for (int x = 0; x < MATRIX_WIDTH; x++) {
			byte index = pgm_read_byte((prog_void*)(data->sequence + currentFrameIndex * fs + y * MATRIX_WIDTH + x));
			short offset = x + y * MATRIX_WIDTH;
			shared_frame[offset][0] = pgm_read_byte((prog_void*)(data->color_palette + index * 3));
			shared_frame[offset][1] = pgm_read_byte((prog_void*)(data->color_palette + index * 3 + 1));
			shared_frame[offset][2] = pgm_read_byte((prog_void*)(data->color_palette + index * 3 + 2));
		}
	}
	return (byte*)shared_frame;
}

PaletteSequencePlayer paletteSequencePlayer;