#include "Config.h"

const PROGMEM palette_sequence_t dummy_sequence = {
{
  { 0x00, 0x00, 0x00, 0x00, 0x00 }, 
  { 0x01, 0x00, 0x00, 0x00, 0x00 }, 
  { 0x00, 0x00, 0x01, 0x00, 0x00 }, 
  { 0x00, 0x00, 0x00, 0x00, 0x00 }, 
  { 0x01, 0x00, 0x00, 0x01, 0x00 }}, 
{
  { 0x00, 0x00, 0x00, 0x00, 0x00 }, 
  { 0x00, 0x02, 0x00, 0x00, 0x02 }, 
  { 0x00, 0x00, 0x00, 0x00, 0x00 }, 
  { 0x02, 0x00, 0x00, 0x00, 0x00 }, 
  { 0x02, 0x00, 0x00, 0x02, 0x00 }}, 
{
  { 0x00, 0x00, 0x00, 0x00, 0x00 }, 
  { 0x00, 0x00, 0x03, 0x00, 0x00 }, 
  { 0x00, 0x00, 0x00, 0x00, 0x03 }, 
  { 0x03, 0x00, 0x00, 0x00, 0x00 }, 
  { 0x00, 0x00, 0x00, 0x03, 0x00 }}, 
{
  { 0x00, 0x00, 0x00, 0x00, 0x00 }, 
  { 0x04, 0x00, 0x00, 0x00, 0x00 }, 
  { 0x00, 0x00, 0x04, 0x00, 0x00 }, 
  { 0x00, 0x04, 0x00, 0x00, 0x00 }, 
  { 0x00, 0x00, 0x00, 0x04, 0x00 }}};

const PROGMEM color_palette_t dummy_palette = {
  { 0x00, 0x00, 0x00 }, 
  { 0xe7, 0x02, 0x02 }, 
  { 0xd6, 0xc8, 0x21 }, 
  { 0x3a, 0xe1, 0x2e }, 
  { 0x42, 0x21, 0xb2 }};

const palette_sequence_data_t dummy_program = { (byte*)&dummy_sequence, 4, (byte*)&dummy_palette };
