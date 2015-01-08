
# User Interface

## PRG
LED (Green) and button to Select a Program/Sequence.
A long press will switch to random mode. After that,
any press will leaf the random mode with the current
program active.

## STL
LED (Red) and button that switched and indicates Sound-to-Light mode.

## SPEED/SENSE
A poti to adjust the speed in normal mode or sensitivity in Sount-to-Light mode.

## XFADE
Crossfade between steps in a sequence.

## MISC
LED (Blue) and button for future extension...

# Implementation

## Backlog

### Palette based storing
Instead of storing full RGB values store indices into a palette for each sequence.
Then we do not need _Export to C_ in the Sequencer but a special tool that parses
the JSON file and generates a header file with a palette and sequence C array from it.
