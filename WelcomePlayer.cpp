#include <avr/pgmspace.h>
#include "WelcomePlayer.h"

WelcomePlayer::WelcomePlayer() {
	x_max = sizeof(welcome_text_scroll) / matrixHeight;
}

void WelcomePlayer::configure(void* d) {
	x_pos = 0;
	get_frame_count = 0;
	fillFrame();
}

void WelcomePlayer::beat() {
}

byte* WelcomePlayer::getFrame() {
	if (get_frame_count >= (target_fps / 4)) {
		// update 4 times per second
		get_frame_count = 0;
		x_pos++;
		if (x_pos >= x_max) {
			// we are done with the welcome text
			return NULL;
		}
		fillFrame();
	}
	else {
		get_frame_count++;
	}
	return (byte*)shared_frame;
}

void WelcomePlayer::fillFrame() {
	int ix;
	int iy;
	byte pixel;
	for (iy = 0; iy < matrixHeight; iy++) {
		for (ix = 0; ix < matrixWidth; ix++) {
			pixel = pgm_read_byte(welcome_text_scroll + (ix + x_pos) + (iy * x_max));
			short offset = ix + iy * matrixWidth;
			if (pixel == 1) {
				shared_frame[offset][0] = 63 * iy;
				shared_frame[offset][1] = 255 - (63 * iy);
				shared_frame[offset][2] = x_pos * 4;
			} else {
				shared_frame[offset][0] = 0;
				shared_frame[offset][1] = 0;
				shared_frame[offset][2] = 15;
			}
		}
	}
}

WelcomePlayer welcomePlayer;
