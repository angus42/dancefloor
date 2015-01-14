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
	for (int y = 0; y < matrixHeight; y++) {
		for (int x = 0; x < matrixWidth; x++) {
			byte index = pgm_read_byte((prog_void*)(data->sequence + currentFrameIndex * fs + y * matrixWidth + x));
			short offset = x + y * matrixWidth;
			shared_frame[offset][0] = pgm_read_byte((prog_void*)(data->color_palette + index * 3));
			shared_frame[offset][1] = pgm_read_byte((prog_void*)(data->color_palette + index * 3 + 1));
			shared_frame[offset][2] = pgm_read_byte((prog_void*)(data->color_palette + index * 3 + 2));
		}
	}
	return (byte*)shared_frame;
}

PaletteSequencePlayer paletteSequencePlayer;