#include "Config.h"

const PROGMEM palette_sequence_t alarm_sequence = {
{
  0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x01, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00
},
{
  0x00, 0x00, 0x00, 0x00, 0x00, 
  0x00, 0x02, 0x02, 0x02, 0x00, 
  0x00, 0x02, 0x03, 0x02, 0x00, 
  0x00, 0x02, 0x02, 0x02, 0x00, 
  0x00, 0x00, 0x00, 0x00, 0x00
},
{
  0x04, 0x04, 0x04, 0x04, 0x04, 
  0x04, 0x02, 0x02, 0x02, 0x04, 
  0x04, 0x02, 0x01, 0x02, 0x04, 
  0x04, 0x02, 0x02, 0x02, 0x04, 
  0x04, 0x04, 0x04, 0x04, 0x04
},
{
  0x04, 0x04, 0x04, 0x04, 0x04, 
  0x04, 0x02, 0x02, 0x02, 0x04, 
  0x04, 0x02, 0x00, 0x02, 0x04, 
  0x04, 0x02, 0x02, 0x02, 0x04, 
  0x04, 0x04, 0x04, 0x04, 0x04
},
{
  0x04, 0x04, 0x04, 0x04, 0x04, 
  0x04, 0x00, 0x00, 0x00, 0x04, 
  0x04, 0x00, 0x00, 0x00, 0x04, 
  0x04, 0x00, 0x00, 0x00, 0x04, 
  0x04, 0x04, 0x04, 0x04, 0x04
}};

const PROGMEM color_palette_t alarm_palette = {
  { 0x00, 0x00, 0x00 }, 
  { 0x2f, 0xff, 0x00 }, 
  { 0x00, 0xae, 0xff }, 
  { 0x0d, 0xff, 0x00 }, 
  { 0xff, 0x00, 0x00 }};

const palette_sequence_data_t alarm_program = { (byte*)&alarm_sequence, 5, (byte*)&alarm_palette };
