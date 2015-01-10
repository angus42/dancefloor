#include "Config.h"
#include "FourColor.h"
#include "rainbow_diag_top_to_bottom_sequence.h"

static sequence_data_t sequences[] = {
	{ (byte*)&FourColor, sizeof(FourColor) / sizeof(frame_t) },
	{ (byte*)&rainbow_diag_top_to_bottom_sequence, sizeof(rainbow_diag_top_to_bottom_sequence) / sizeof(frame_t) }
};