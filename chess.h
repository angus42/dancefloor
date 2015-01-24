#include "Config.h"

const PROGMEM palette_sequence_t chess_sequence = {
{
  0x00, 0x01, 0x00, 0x01, 0x00, 
  0x01, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x01, 0x00, 0x01, 0x00, 
  0x01, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x01, 0x00, 0x01, 0x00
},
{
  0x01, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x01, 0x00, 0x01, 0x00, 
  0x01, 0x00, 0x01, 0x00, 0x01, 
  0x00, 0x01, 0x00, 0x01, 0x00, 
  0x01, 0x00, 0x01, 0x00, 0x01
}};

const PROGMEM color_palette_t chess_palette = {
  { 0xff, 0xff, 0xff }, 
  { 0x00, 0x00, 0x00 }};

const palette_sequence_data_t chess_program = { (byte*)&chess_sequence, 2, (byte*)&chess_palette, false };
