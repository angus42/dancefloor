#include "SequencePlayer.h"

SequencePlayer::SequencePlayer() {
}

void SequencePlayer::configure(void* d) {
	data = (sequence_data_t*)d;
	currentFrameIndex = 0;
}

void SequencePlayer::moveNextFrame() {
	currentFrameIndex++;
	if (currentFrameIndex >= data->frame_count)
		currentFrameIndex = 0;

#ifdef _DEBUG
	Serial.print("f");
	Serial.print(currentFrameIndex);
#endif
}

byte* SequencePlayer::getCurrentFrame() {
	if (data->sequence == NULL)
		return NULL;

	int fs = sizeof(frame_t);
	return (byte*)(data->sequence + currentFrameIndex * fs);
}


