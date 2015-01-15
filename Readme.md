
# User Interface

## PRG
LED (Green) and button to Select a Program/Sequence.
A long press will switch to random mode. After that,
any press will leaf the random mode with the current
program active.

## STL
LED (Red) and button that switched and indicates Sound-to-Light mode.

## SPEED (SENSE)
A poti to adjust the speed in normal mode (or sensitivity in Sount-to-Light mode).

_Notice:_ Sound-to-Light sensitivity is not supported in the current hardware version.

## MISC
LED (Blue) and button for future extension...

# Implementation

## Backlog

### Palette based storing
Instead of storing full RGB values store indices into a palette for each sequence.
Then we do not need _Export to C_ in the Sequencer but a special tool that parses
the JSON file and generates a header file with a palette and sequence C array from it.

### Random program change
Change program automatically after a random amount of beats. Range of possible beats is 2 to 60,
maybe with a (gausian) norman distribution. The target program is also selected randomly
(welcome program excluded).

### Frame Interpolation
Helper function to interpolate between two frames (Crossfade).
A sequence program must opt in for this.


## Used third party software

[Adafruit WS2801 Library on GitHub](https://github.com/adafruit/Adafruit-WS2801-Library)

[Plasma code by bidouille](http://www.bidouille.org/prog/plasma)

[Gaussian distribution class by Ivan Seidel Gomes](https://github.com/ivanseidel/Gaussian)

