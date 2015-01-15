#include "Config.h"

#include "WelcomePlayer.h"
// #include "SequencePlayer.h"
#include "PaletteSequencePlayer.h"
#include "PlasmaPlayer.h"

// #include "dummy.h"
#include "jumping_blossom.h"
#include "walking_tripples.h"
#include "rainbow_diag_top_to_bottom.h"

static program_data_t programs[5];

void init_programs() {
	programs[0] = (program_data_t) { &welcomePlayer, NULL };
	programs[1] = (program_data_t) { &paletteSequencePlayer, (void*)&jumping_blossom_program };
	programs[2] = (program_data_t) { &paletteSequencePlayer, (void*)&walking_tripples_program };
	programs[3] = (program_data_t) { &paletteSequencePlayer, (void*)&rainbow_diag_top_to_bottom_program };
	programs[4] = (program_data_t) { &plasmaPlayer, NULL };
}

