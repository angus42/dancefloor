#include "Config.h"

#include "WelcomePlayer.h"
#include "SequencePlayer.h"
#include "PlasmaPlayer.h"

#include "FourColor.h"
#include "rainbow_diag_top_to_bottom_sequence.h"

const sequence_data_t FourColor_sequence_data = { (byte*)&FourColor, sizeof(FourColor) / sizeof(frame_t) };
const sequence_data_t rainbow_diag_top_to_bottom_sequence_data = { (byte*)&rainbow_diag_top_to_bottom_sequence, sizeof(rainbow_diag_top_to_bottom_sequence) / sizeof(frame_t) };

static program_data_t programs[4];

void init_programs() {
	programs[0] = (program_data_t) { &welcomePlayer, NULL };
	programs[1] = (program_data_t) { &sequencePlayer, (void*)&FourColor_sequence_data };
	programs[2] = (program_data_t) { &sequencePlayer, (void*)&rainbow_diag_top_to_bottom_sequence_data };
	programs[3] = (program_data_t) { &plasmaPlayer, NULL };
}

