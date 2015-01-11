#include "Config.h"
#include "FourColor.h"
#include "rainbow_diag_top_to_bottom_sequence.h"

SequencePlayer* sequencePlayer;

const sequence_data_t FourColor_sequence_data = { (byte*)&FourColor, sizeof(FourColor) / sizeof(frame_t) };
const sequence_data_t rainbow_diag_top_to_bottom_sequence_data = { (byte*)&rainbow_diag_top_to_bottom_sequence, sizeof(rainbow_diag_top_to_bottom_sequence) / sizeof(frame_t) };

program_data_t programs[2];

void init_programs() {
	sequencePlayer = new SequencePlayer();
	programs[0] = (program_data_t) { sequencePlayer, (void*)&FourColor_sequence_data };
	programs[1] = (program_data_t) { sequencePlayer, (void*)&rainbow_diag_top_to_bottom_sequence_data };
}

