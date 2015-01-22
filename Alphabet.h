#include "Config.h"

const PROGMEM byte alphabet[][5] = {
{ //  
  B00000000, 
  B00000000, 
  B00000000, 
  B00000000, 
  B00000000},
{ // !
  B00000000, 
  B00000000, 
  B00010111, 
  B00000000, 
  B00000000},
{ // "
  B00000000, 
  B00000011, 
  B00000000, 
  B00000011, 
  B00000000},
{ // #
  B00001010, 
  B00011111, 
  B00001010, 
  B00011111, 
  B00001010},
{ // $
  B00010010, 
  B00010101, 
  B00011111, 
  B00010101, 
  B00001001},
{ // %
  B00010010, 
  B00001000, 
  B00000100, 
  B00000010, 
  B00010001},
{ // &
  B00000000, 
  B00001010, 
  B00010101, 
  B00001010, 
  B00010000},
{ // '
  B00000000, 
  B00000000, 
  B00000011, 
  B00000000, 
  B00000000},
{ // (
  B00000000, 
  B00001110, 
  B00010001, 
  B00000000, 
  B00000000},
{ // )
  B00000000, 
  B00010001, 
  B00001110, 
  B00000000, 
  B00000000},
{ // *
  B00000000, 
  B00001010, 
  B00000100, 
  B00001010, 
  B00000000},
{ // +
  B00000000, 
  B00000100, 
  B00001110, 
  B00000100, 
  B00000000},
{ // ,
  B00000000, 
  B00010000, 
  B00001000, 
  B00000000, 
  B00000000},
{ // -
  B00000000, 
  B00000100, 
  B00000100, 
  B00000100, 
  B00000000},
{ // .
  B00000000, 
  B00000000, 
  B00010000, 
  B00000000, 
  B00000000},
{ // /
  B00010000, 
  B00001000, 
  B00000100, 
  B00000010, 
  B00000001},
{ // 0
  B00001110, 
  B00010001, 
  B00001110, 
  B00000000, 
  B00000000},
{ // 1
  B00000000, 
  B00000001, 
  B00011111, 
  B00000000, 
  B00000000},
{ // 2
  B00000000, 
  B00011001, 
  B00010101, 
  B00010010, 
  B00000000},
{ // 3
  B00000000, 
  B00010001, 
  B00010101, 
  B00001010, 
  B00000000},
{ // 4
  B00000000, 
  B00000111, 
  B00000100, 
  B00011111, 
  B00000000},
{ // 5
  B00000000, 
  B00010011, 
  B00010101, 
  B00001001, 
  B00000000},
{ // 6
  B00000000, 
  B00001110, 
  B00010101, 
  B00001001, 
  B00000000},
{ // 7
  B00000000, 
  B00011001, 
  B00000101, 
  B00000011, 
  B00000000},
{ // 8
  B00000000, 
  B00001010, 
  B00010101, 
  B00001010, 
  B00000000},
{ // 9
  B00000000, 
  B00010010, 
  B00010101, 
  B00001110, 
  B00000000},
{ // :
  B00000000, 
  B00000000, 
  B00001010, 
  B00000000, 
  B00000000},
{ // ;
  B00000000, 
  B00010000, 
  B00001010, 
  B00000000, 
  B00000000},
{ // <
  B00000000, 
  B00000100, 
  B00001010, 
  B00010001, 
  B00000000},
{ // =
  B00000000, 
  B00001010, 
  B00001010, 
  B00001010, 
  B00000000},
{ // >
  B00000000, 
  B00010001, 
  B00001010, 
  B00000100, 
  B00000000},
{ // ?
  B00000000, 
  B00000001, 
  B00010101, 
  B00000010, 
  B00000000},
{ // @
  B00001110, 
  B00010001, 
  B00010111, 
  B00010101, 
  B00001010},
{ // A
  B00011110, 
  B00000101, 
  B00000101, 
  B00011110, 
  B00000000},
{ // B
  B00011111, 
  B00010101, 
  B00010101, 
  B00001110, 
  B00000000},
{ // C
  B00001110, 
  B00010001, 
  B00010001, 
  B00010001, 
  B00000000},
{ // D
  B00011111, 
  B00010001, 
  B00010001, 
  B00001110, 
  B00000000},
{ // E
  B00011111, 
  B00010101, 
  B00010101, 
  B00010001, 
  B00000000},
{ // F
  B00011111, 
  B00000101, 
  B00000101, 
  B00000001, 
  B00000000},
{ // G
  B00001110, 
  B00010001, 
  B00010101, 
  B00001101, 
  B00000000},
{ // H
  B00011111, 
  B00000100, 
  B00000100, 
  B00011111, 
  B00000000},
{ // I
  B00000000, 
  B00010001, 
  B00011111, 
  B00010001, 
  B00000000},
{ // J
  B00001001, 
  B00010001, 
  B00010001, 
  B00001111, 
  B00000000},
{ // K
  B00011111, 
  B00000100, 
  B00001010, 
  B00010001, 
  B00000000},
{ // L
  B00011111, 
  B00010000, 
  B00010000, 
  B00010000, 
  B00000000},
{ // M
  B00011111, 
  B00000010, 
  B00000100, 
  B00000010, 
  B00011111},
{ // N
  B00011111, 
  B00000010, 
  B00000100, 
  B00011111, 
  B00000000},
{ // O
  B00001110, 
  B00010001, 
  B00010001, 
  B00001110, 
  B00000000},
{ // P
  B00011111, 
  B00000101, 
  B00000101, 
  B00000010, 
  B00000000},
{ // Q
  B00001110, 
  B00010001, 
  B00010001, 
  B00001110, 
  B00010000},
{ // R
  B00011111, 
  B00000101, 
  B00000101, 
  B00011010, 
  B00000000},
{ // S
  B00010010, 
  B00010101, 
  B00010101, 
  B00001001, 
  B00000000},
{ // T
  B00000001, 
  B00000001, 
  B00011111, 
  B00000001, 
  B00000001},
{ // U
  B00001111, 
  B00010000, 
  B00010000, 
  B00001111, 
  B00000000},
{ // V
  B00000111, 
  B00001000, 
  B00010000, 
  B00001000, 
  B00000111},
{ // W
  B00001111, 
  B00010000, 
  B00001100, 
  B00010000, 
  B00001111},
{ // X
  B00010001, 
  B00001010, 
  B00000100, 
  B00001010, 
  B00010001},
{ // Y
  B00000001, 
  B00000010, 
  B00011100, 
  B00000010, 
  B00000001},
{ // Z
  B00010001, 
  B00011001, 
  B00010101, 
  B00010011, 
  B00010001},
{ // [
  B00000000, 
  B00011111, 
  B00010001, 
  B00000000, 
  B00000000},
{ // \
  B00000001, 
  B00000010, 
  B00000100, 
  B00001000, 
  B00010000},
{ // ]
  B00000000, 
  B00000000, 
  B00010001, 
  B00011111, 
  B00000000},
{ // ^
  B00000000, 
  B00000010, 
  B00000001, 
  B00000010, 
  B00000000},
{ // _
  B00010000, 
  B00010000, 
  B00010000, 
  B00010000, 
  B00010000},
{ // `
  B00011101, 
  B00001010, 
  B00001010, 
  B00011101, 
  B00000000},
{ // a
  B00001101, 
  B00010010, 
  B00010010, 
  B00001101, 
  B00000000},
{ // b
  B00001101, 
  B00010000, 
  B00010000, 
  B00001101, 
  B00000000},
{ // c
  B00011111, 
  B00010001, 
  B00010001, 
  B00011111, 
  B00000000}};
