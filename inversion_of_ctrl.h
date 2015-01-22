#include "Config.h"

const PROGMEM palette_sequence_t inversion_of_ctrl_sequence = {
{
  0x00, 0x00, 0x01, 0x01, 0x01, 
  0x00, 0x00, 0x01, 0x01, 0x01, 
  0x01, 0x01, 0x01, 0x01, 0x01, 
  0x01, 0x01, 0x01, 0x01, 0x01, 
  0x01, 0x01, 0x01, 0x01, 0x01
},
{
  0x01, 0x01, 0x01, 0x01, 0x01, 
  0x01, 0x01, 0x01, 0x01, 0x01, 
  0x01, 0x01, 0x01, 0x01, 0x01, 
  0x01, 0x01, 0x01, 0x02, 0x02, 
  0x01, 0x01, 0x01, 0x02, 0x02
},
{
  0x01, 0x01, 0x03, 0x01, 0x01, 
  0x01, 0x01, 0x03, 0x01, 0x01, 
  0x03, 0x03, 0x03, 0x03, 0x03, 
  0x01, 0x01, 0x03, 0x01, 0x01, 
  0x01, 0x01, 0x03, 0x01, 0x01
},
{
  0x03, 0x03, 0x01, 0x03, 0x03, 
  0x03, 0x03, 0x01, 0x03, 0x03, 
  0x01, 0x01, 0x01, 0x01, 0x01, 
  0x03, 0x03, 0x01, 0x03, 0x03, 
  0x03, 0x03, 0x01, 0x03, 0x03
},
{
  0x01, 0x01, 0x01, 0x04, 0x04, 
  0x01, 0x01, 0x01, 0x04, 0x04, 
  0x01, 0x01, 0x01, 0x01, 0x01, 
  0x01, 0x01, 0x01, 0x01, 0x01, 
  0x01, 0x01, 0x01, 0x01, 0x01
},
{
  0x01, 0x01, 0x01, 0x01, 0x01, 
  0x01, 0x01, 0x01, 0x01, 0x01, 
  0x01, 0x01, 0x01, 0x01, 0x01, 
  0x05, 0x05, 0x01, 0x01, 0x01, 
  0x05, 0x05, 0x01, 0x01, 0x01
},
{
  0x01, 0x01, 0x01, 0x01, 0x01, 
  0x01, 0x01, 0x06, 0x01, 0x01, 
  0x01, 0x06, 0x06, 0x06, 0x01, 
  0x01, 0x01, 0x06, 0x01, 0x01, 
  0x01, 0x01, 0x01, 0x01, 0x01
},
{
  0x07, 0x07, 0x07, 0x07, 0x07, 
  0x07, 0x07, 0x01, 0x07, 0x07, 
  0x07, 0x01, 0x01, 0x01, 0x07, 
  0x07, 0x07, 0x01, 0x07, 0x07, 
  0x07, 0x07, 0x07, 0x07, 0x07
}};

const PROGMEM color_palette_t inversion_of_ctrl_palette = {
  { 0x93, 0x39, 0xea }, 
  { 0x00, 0x00, 0x00 }, 
  { 0x70, 0x00, 0xdd }, 
  { 0xff, 0xff, 0xff }, 
  { 0x4d, 0x00, 0x98 }, 
  { 0x30, 0x00, 0x5f }, 
  { 0xd0, 0x00, 0x3f }, 
  { 0x4d, 0x00, 0x17 }};

const palette_sequence_data_t inversion_of_ctrl_program = { (byte*)&inversion_of_ctrl_sequence, 8, (byte*)&inversion_of_ctrl_palette, false };
