#include "Config.h"

#include "WelcomePlayer.h"
// #include "SequencePlayer.h"
#include "PaletteSequencePlayer.h"
#include "PlasmaPlayer.h"

#include "dummy.h"
#include "rainbow_diag_top_to_bottom.h"

static program_data_t programs[4];

void init_programs() {
	programs[0] = (program_data_t) { &welcomePlayer, NULL };
	programs[1] = (program_data_t) { &paletteSequencePlayer, (void*)&dummy_program };
	programs[2] = (program_data_t) { &paletteSequencePlayer, (void*)&rainbow_diag_top_to_bottom_program };
	programs[3] = (program_data_t) { &plasmaPlayer, NULL };
}

