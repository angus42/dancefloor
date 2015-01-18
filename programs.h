#include "Config.h"

#include "WelcomePlayer.h"
// #include "SequencePlayer.h"
#include "PaletteSequencePlayer.h"
#include "PlasmaPlayer.h"

#include "alarm.h"
#include "black_and_white.h"
#include "jumping_blossom.h"
#include "pong.h"
#include "rainbow_diag_top_to_bottom.h"
#include "rot_drehend.h"
#include "walking_tripples.h"

static program_data_t programs[9];

void init_programs() {
	programs[0] = (program_data_t) { &welcomePlayer, NULL };
	programs[1] = (program_data_t) { &paletteSequencePlayer, (void*)&alarm_program };
	programs[2] = (program_data_t) { &paletteSequencePlayer, (void*)&jumping_blossom_program };
	programs[3] = (program_data_t) { &paletteSequencePlayer, (void*)&pong_program };
	programs[4] = (program_data_t) { &paletteSequencePlayer, (void*)&rainbow_diag_top_to_bottom_program };
	programs[5] = (program_data_t) { &paletteSequencePlayer, (void*)&rot_drehend_program };
	programs[6] = (program_data_t) { &paletteSequencePlayer, (void*)&walking_tripples_program };
	programs[7] = (program_data_t) { &paletteSequencePlayer, (void*)&black_and_white_program };
	programs[8] = (program_data_t) { &plasmaPlayer, NULL };
}

