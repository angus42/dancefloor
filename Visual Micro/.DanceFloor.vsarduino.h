/* 
	Editor: http://www.visualmicro.com
	        visual micro and the arduino ide ignore this code during compilation. this code is automatically maintained by visualmicro, manual changes to this file will be overwritten
	        the contents of the Visual Micro sketch sub folder can be deleted prior to publishing a project
	        all non-arduino files created by visual micro and all visual studio project or solution files can be freely deleted and are not required to compile a sketch (do not delete your own code!).
	        note: debugger breakpoints are stored in '.sln' or '.asln' files, knowledge of last uploaded breakpoints is stored in the upload.vmps.xml file. Both files are required to continue a previous debug session without needing to compile and upload again
	
	Hardware: Arduino Uno, Platform=avr, Package=arduino
*/

#ifndef _VSARDUINO_H_
#define _VSARDUINO_H_
#define __AVR_ATmega328p__
#define __AVR_ATmega328P__
#define ARDUINO 106
#define ARDUINO_MAIN
#define __AVR__
#define __avr__
#define F_CPU 16000000L
#define __cplusplus
#define __inline__
#define __asm__(x)
#define __extension__
#define __ATTR_PURE__
#define __ATTR_CONST__
#define __inline__
#define __asm__ 
#define __volatile__

#define __builtin_va_list
#define __builtin_va_start
#define __builtin_va_end
#define __DOXYGEN__
#define __attribute__(x)
#define NOINLINE __attribute__((noinline))
#define prog_void
#define PGM_VOID_P int
            
typedef unsigned char byte;
extern "C" void __cxa_pure_virtual() {;}

//
//
void soundTrigger();

#include "C:\Program Files (x86)\Arduino\hardware\arduino\cores\arduino\arduino.h"
#include "C:\Program Files (x86)\Arduino\hardware\arduino\variants\standard\pins_arduino.h" 
#include "C:\Users\angus\Source\Repos\dancefloor\DanceFloor.ino"
#include "C:\Users\angus\Source\Repos\dancefloor\Adafruit_WS2801.cpp"
#include "C:\Users\angus\Source\Repos\dancefloor\Adafruit_WS2801.h"
#include "C:\Users\angus\Source\Repos\dancefloor\Alphabet.h"
#include "C:\Users\angus\Source\Repos\dancefloor\Config.h"
#include "C:\Users\angus\Source\Repos\dancefloor\Controller.cpp"
#include "C:\Users\angus\Source\Repos\dancefloor\Controller.h"
#include "C:\Users\angus\Source\Repos\dancefloor\FrameRenderer.cpp"
#include "C:\Users\angus\Source\Repos\dancefloor\FrameRenderer.h"
#include "C:\Users\angus\Source\Repos\dancefloor\Gaussian.h"
#include "C:\Users\angus\Source\Repos\dancefloor\MemoryFree.cpp"
#include "C:\Users\angus\Source\Repos\dancefloor\MemoryFree.h"
#include "C:\Users\angus\Source\Repos\dancefloor\PaletteSequencePlayer.cpp"
#include "C:\Users\angus\Source\Repos\dancefloor\PaletteSequencePlayer.h"
#include "C:\Users\angus\Source\Repos\dancefloor\PlasmaPlayer.cpp"
#include "C:\Users\angus\Source\Repos\dancefloor\PlasmaPlayer.h"
#include "C:\Users\angus\Source\Repos\dancefloor\Player.cpp"
#include "C:\Users\angus\Source\Repos\dancefloor\Player.h"
#include "C:\Users\angus\Source\Repos\dancefloor\S.h"
#include "C:\Users\angus\Source\Repos\dancefloor\SequencePlayer.cpp"
#include "C:\Users\angus\Source\Repos\dancefloor\SequencePlayer.h"
#include "C:\Users\angus\Source\Repos\dancefloor\TextPlayer.cpp"
#include "C:\Users\angus\Source\Repos\dancefloor\TextPlayer.h"
#include "C:\Users\angus\Source\Repos\dancefloor\WelcomePlayer.cpp"
#include "C:\Users\angus\Source\Repos\dancefloor\WelcomePlayer.h"
#include "C:\Users\angus\Source\Repos\dancefloor\alarm.h"
#include "C:\Users\angus\Source\Repos\dancefloor\black_and_white.h"
#include "C:\Users\angus\Source\Repos\dancefloor\blinky_pinky_inky.h"
#include "C:\Users\angus\Source\Repos\dancefloor\chess.h"
#include "C:\Users\angus\Source\Repos\dancefloor\colors.h"
#include "C:\Users\angus\Source\Repos\dancefloor\curtain_with_a_smile.h"
#include "C:\Users\angus\Source\Repos\dancefloor\double_spinner.h"
#include "C:\Users\angus\Source\Repos\dancefloor\flashing_yellow_clockwork.h"
#include "C:\Users\angus\Source\Repos\dancefloor\fscale.h"
#include "C:\Users\angus\Source\Repos\dancefloor\game.h"
#include "C:\Users\angus\Source\Repos\dancefloor\heart.h"
#include "C:\Users\angus\Source\Repos\dancefloor\hofrat_keller.h"
#include "C:\Users\angus\Source\Repos\dancefloor\inversion_of_ctrl.h"
#include "C:\Users\angus\Source\Repos\dancefloor\jumping_blossom.h"
#include "C:\Users\angus\Source\Repos\dancefloor\maiwald.h"
#include "C:\Users\angus\Source\Repos\dancefloor\pong.h"
#include "C:\Users\angus\Source\Repos\dancefloor\programs.h"
#include "C:\Users\angus\Source\Repos\dancefloor\rainbow_diag_top_to_bottom.h"
#include "C:\Users\angus\Source\Repos\dancefloor\rot_drehend.h"
#include "C:\Users\angus\Source\Repos\dancefloor\secret_message.h"
#include "C:\Users\angus\Source\Repos\dancefloor\spirale.h"
#include "C:\Users\angus\Source\Repos\dancefloor\this_side_up.h"
#include "C:\Users\angus\Source\Repos\dancefloor\walking_tripples.h"
#include "C:\Users\angus\Source\Repos\dancefloor\wild_at_heart.h"
#include "C:\Users\angus\Source\Repos\dancefloor\wurm.h"
#endif
