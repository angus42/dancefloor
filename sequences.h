#include "Config.h"
#include "FourColor.h"
#include "rainbow_diag_top_to_bottom_sequence.h"

const sequence_data_t FourColor_sequence_data = { (byte*)&FourColor, sizeof(FourColor) / sizeof(frame_t) };
const sequence_data_t rainbow_diag_top_to_bottom_sequence_data = { (byte*)&rainbow_diag_top_to_bottom_sequence, sizeof(rainbow_diag_top_to_bottom_sequence) / sizeof(frame_t) };

static sequence_data_t sequences[] = {
	FourColor_sequence_data,
        rainbow_diag_top_to_bottom_sequence_data
};

SequencePlayer sequencePlayer;

static program_data_t programs[] = {
  { &sequencePlayer, (void*) &FourColor_sequence_data },
  { &sequencePlayer, (void*) &rainbow_diag_top_to_bottom_sequence_data }
};
