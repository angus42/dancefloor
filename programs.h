#include "Config.h"

#include "WelcomePlayer.h"
#include "PaletteSequencePlayer.h"
#include "TextPlayer.h"

#include "alarm.h"
#include "black_and_white.h"
#include "blinky_pinky_inky.h"
#include "chess.h"
#include "colors.h"
#include "curtain_with_a_smile.h"
#include "double_spinner.h"
#include "flashing_yellow_clockwork.h"
#include "game.h"
#include "heart.h"
#include "hofrat_keller.h"
#include "inversion_of_ctrl.h"
#include "jumping_blossom.h"
#include "maiwald.h"
#include "pong.h"
#include "rainbow_diag_top_to_bottom.h"
#include "rot_drehend.h"
#include "S.h"
#include "saterday_night_fever.h"
#include "secret_message.h"
#include "spirale.h"
#include "walking_tripples.h"
#include "wild_at_heart.h"
#include "wurm.h"

static program_data_t programs[26];

// const PROGMEM char welcome_text[] = "HALLO HOWY \xA9 \x00";

void init_programs() {
	programs[0] = (program_data_t) { &welcomePlayer, NULL };
	programs[1] = (program_data_t) { &paletteSequencePlayer, (void*)&alarm_program };
	programs[2] = (program_data_t) { &paletteSequencePlayer, (void*)&curtain_with_a_smile_program };
	programs[3] = (program_data_t) { &paletteSequencePlayer, (void*)&hofrat_keller_program };
	programs[4] = (program_data_t) { &paletteSequencePlayer, (void*)&inversion_of_ctrl_program };
	programs[5] = (program_data_t) { &paletteSequencePlayer, (void*)&jumping_blossom_program };
	programs[6] = (program_data_t) { &paletteSequencePlayer, (void*)&pong_program };
	programs[7] = (program_data_t) { &paletteSequencePlayer, (void*)&rainbow_diag_top_to_bottom_program };
	programs[8] = (program_data_t) { &paletteSequencePlayer, (void*)&rot_drehend_program };
	programs[9] = (program_data_t) { &paletteSequencePlayer, (void*)&walking_tripples_program };
	programs[10] = (program_data_t) { &paletteSequencePlayer, (void*)&wild_at_heart_program };
	programs[11] = (program_data_t) { &paletteSequencePlayer, (void*)&S_program };
	programs[12] = (program_data_t) { &paletteSequencePlayer, (void*)&secret_message_program };
	programs[13] = (program_data_t) { &paletteSequencePlayer, (void*)&maiwald_program };
	programs[14] = (program_data_t) { &paletteSequencePlayer, (void*)&wurm_program };
	programs[15] = (program_data_t) { &paletteSequencePlayer, (void*)&blinky_pinky_inky_program };
	programs[16] = (program_data_t) { &paletteSequencePlayer, (void*)&double_spinner_program };
	programs[17] = (program_data_t) { &paletteSequencePlayer, (void*)&flashing_yellow_clockwork_program };
	programs[18] = (program_data_t) { &paletteSequencePlayer, (void*)&chess_program };
	programs[19] = (program_data_t) { &paletteSequencePlayer, (void*)&colors_program };
	programs[20] = (program_data_t) { &paletteSequencePlayer, (void*)&game_program };
	programs[21] = (program_data_t) { &paletteSequencePlayer, (void*)&heart_program };
	programs[22] = (program_data_t) { &paletteSequencePlayer, (void*)&spirale_program };
	programs[23] = (program_data_t) { &paletteSequencePlayer, (void*)&saterday_night_fever_program };
	programs[24] = (program_data_t) { &paletteSequencePlayer, (void*)&black_and_white_program };
	programs[25] = (program_data_t) { &textPlayer, NULL };
}

