#include <avr/pgmspace.h>
#include "PaletteSequencePlayer.h"

PaletteSequencePlayer::PaletteSequencePlayer() {
}

void PaletteSequencePlayer::configure(void* d) {
	data = (palette_sequence_data_t*)d;
	currentFrameIndex = 0;
	lastFrame = NULL;
}

void PaletteSequencePlayer::beat() {
	lastFrame = (data->sequence + (currentFrameIndex * sizeof(palette_frame_t)));
	currentFrameIndex++;
	if (currentFrameIndex >= data->frame_count)
		currentFrameIndex = 0;

#ifdef _DEBUG
	Serial.print("f");
	Serial.print(currentFrameIndex);
#endif
}

byte* PaletteSequencePlayer::getFrame(float beat_percentage) {
	if (data->sequence == NULL)
		return NULL;

	bool xfade = lastFrame != NULL && data->xfade && beat_percentage < 1;

	int fs = sizeof(palette_frame_t);
	for (int y = 0; y < MATRIX_HEIGHT; y++) {
		for (int x = 0; x < MATRIX_WIDTH; x++) {
			byte index = pgm_read_byte((prog_void*)(data->sequence + currentFrameIndex * fs + y * MATRIX_WIDTH + x));
			short offset = x + y * MATRIX_WIDTH;
			if (!xfade) {
				shared_frame[offset][0] = lookup(index, 0);
				shared_frame[offset][1] = lookup(index, 1);
				shared_frame[offset][2] = lookup(index, 2);
			} else {
				byte source_index = pgm_read_byte((prog_void*)(lastFrame + y * MATRIX_WIDTH + x));
				shared_frame[offset][0] = interpolate(source_index, index, beat_percentage, 0);
				shared_frame[offset][1] = interpolate(source_index, index, beat_percentage, 1);
				shared_frame[offset][2] = interpolate(source_index, index, beat_percentage, 2);
			}
		}
	}
	return (byte*)shared_frame;
}

byte PaletteSequencePlayer::lookup(uint8_t index, uint8_t component_index) {
	return pgm_read_byte((prog_void*)(data->color_palette + index * 3 + component_index));
}

byte PaletteSequencePlayer::interpolate(uint8_t source_index, uint8_t target_index, float percentage, uint8_t component_index) {
	byte source = lookup(source_index, component_index);
	byte target = lookup(target_index, component_index);
	return source + ((float)(target - source) * percentage);
}

PaletteSequencePlayer paletteSequencePlayer;