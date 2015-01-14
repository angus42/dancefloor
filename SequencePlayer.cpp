#include <avr/pgmspace.h>
#include "SequencePlayer.h"

SequencePlayer::SequencePlayer() {
}

void SequencePlayer::configure(void* d) {
	data = (sequence_data_t*)d;
	currentFrameIndex = 0;
}

void SequencePlayer::beat() {
	currentFrameIndex++;
	if (currentFrameIndex >= data->frame_count)
		currentFrameIndex = 0;

#ifdef _DEBUG
	Serial.print("f");
	Serial.print(currentFrameIndex);
#endif
}

byte* SequencePlayer::getFrame() {
	if (data->sequence == NULL)
		return NULL;

	int fs = sizeof(frame_t);
	memcpy_P(&shared_frame, (prog_void*)(data->sequence + currentFrameIndex * fs), fs);
	return (byte*)shared_frame;
}

SequencePlayer sequencePlayer;