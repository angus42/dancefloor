#include <math.h>
#include "PlasmaPlayer.h"

PlasmaPlayer::PlasmaPlayer() {
	bps = 1.0;
}

void PlasmaPlayer::configure(void* d) {
	frame_count = 0;
	beat_frame_count = 0;
}

void PlasmaPlayer::beat() {
	bps = (float)beat_frame_count / (float)target_fps;
	beat_frame_count = 0;
}

byte* PlasmaPlayer::getFrame(float beat_percentage) {
	frame_count++;
	beat_frame_count++;

	float time = ((float)frame_count / (float)target_fps) * bps;
	// this might become very sensitive to bps changes over time
	// so we reset after each the period, though there might be a little glitch
	if (time >= plasma_period) {
		frame_count = 0;
		time = 0;
	}

	float kx = (float)MATRIX_WIDTH / (float)MATRIX_HEIGHT;
	for (uint8_t y = 0; y < MATRIX_HEIGHT; y++) {
		float yy = y / (float)MATRIX_HEIGHT - .5;
		for (uint8_t x = 0; x < MATRIX_WIDTH; x++) {
			float xx = kx * x / (float)MATRIX_WIDTH - kx / 2.0;
			double v = plasma(xx, yy, time);
			colorMap(x, y, v);
		}
	}

	return (byte*)shared_frame;
}

double PlasmaPlayer::plasma(float x, float y, float time) {
	double v = 0;
	v += sin((x * 10 + time));
	v += sin((y * 10 + time) / 2.0);
	v += sin((x * 10 + y * 10 + time) / 2.0);
	double cx = x + .5 * sin(time / 5.0);
	double cy = y + .5 * cos(time / 3.0);
	v += sin(sqrt(100 * (cx*cx + cy*cy) + 1) + time);
	v = v / 2.0;
	return v;
}

void PlasmaPlayer::colorMap(uint8_t x, uint8_t y, double v) {
	short offset = x + y * MATRIX_WIDTH;
	shared_frame[offset][0] = 255 * (.5 + .5 * sin(PI * v));
	shared_frame[offset][1] = 255 * (.5 + .5 * cos(PI * v));
	shared_frame[offset][2] = 0;
}

PlasmaPlayer plasmaPlayer;
