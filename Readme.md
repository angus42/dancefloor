# Introduction

## Acknowledgment

This project started of as a birthday gift for a good friend. He is fond of colorful
blinking lights. As he called for a 70s disco birthday party, the idea for this project
was born.

> Dedicated to Howy. Happy birthday to your 0x28th birthday.

## What is this

The dance floor is a ca. 20 x 20 cm flat box with 25 full color RGB LEDs. It is controlled
by an [Arduino] Uno microcontroller board. Programming the controller so that the lights
light up in a useful manner is all the fun of the project. For now it can play
sequences of frames that change to the rhythm of music or at a adjustable bpm
(beats per minute) rate.

![dance floor](DanceFloor.jpg "Picture of the dance floor and a tablet for size comparison")

# Usage

At startup a fixed welcome text is played. It can be skipped by pressing the *PROG*
button.

## Plugs and controls

On one side there is the power plug and the USB plug.
On the other side there is the (blue) *PROG* button, the (red) *MODE* button
and a *SPEED* poti knob.

## Switching programs

A program is usually a sequence of frames that repeats over and over. You can
toggle programs by pressing the *PROG* button.

## Random program change

A long press on the *PROG* button will switch to random mode.
The program will change automatically after a random amount of seconds between
1 and 20. The time is normal distributed. The next program is also chosen
randomly (welcome program excluded).


Another press of the *PROG* button will leave the random mode with the last program
staying active.

## Sound to light mode

Pressing the *MODE* button will switch between _Sound to light_ and _Beats per minute_ mode.
_Sound to light_ mode is active then the control LED is on.
In this mode, the built-in microphone will trigger the frame change, when a certain
volume is exceeded. The maximum possible rate of frame changes is cut of at 300 bpm.

> In this hardware release the sensitivity can only be adjusted by a small extra poti.
To adjust the sensitivity, change the volume of the music or move the dance floor
away from it (especially the microphone).

## Beats per minute mode

Pressing the *MODE* button will switch between _Sound to light_ and _Beats per minute_ mode.
_Beats per minute_ mode is active then the control LED is off.
In this mode the *SPEED* poti allows you to select a value between 1 and 1800
beats per minute. The last value is equal to 30 frame changes per second.

## Rotation

The patterns on the matrix can be rotated in 90 degree angles. This might be useful
if the dance floor is hung on the wall in a certain orientation. Pressing both the
*MODE* and *PROG* button for one second will change the rotation by one 90 degree
step clockwise. The welcome text will start again to visualize the new orientation.
To rotate another 90 degrees, both buttons must be released and pressed again
for another second. The current orientation is persisted and will be restored
the next time the dance floor is turned on.

# Implementation

## Code tour

### Config.h

This file contains of

+ hardware definition, that is which hardware is connected
  to which I/Os and how big is the LED matrix.
+ timing related constants.
+ shared data types.

### DanceFloor.ino

This is the main Ardu[ino] file. It contains of

+ the setup routine that sets up the hardware and registers an interrupt handler
  for the microphone.
+ the main loop that does 
  + poll the buttons and poti and calls the appropriate _Controller_ functions.
  + call the _loop_ function of the _Controller_ for each frame.
  + wait a calculated amount of milliseconds to maintain the target frame rate.
+ the mentioned interrupt handler that calls a _Controller_ function for each detected sound.

### Controller

```
// TODO
```

### FrameRenderer

This is a simple abstraction between the frame array of rgb values and the
[Adafruit WS2801 library][WS2801 Lib]. It also does the rotation.

### Player.h

```
// TODO
```

### PaletteSequencePlayer
This player can play sequences that are stored as frames of indexes into a
palette array that stores the used colors.
The player can also interpolate between two frames (Crossfade).
A sequence program must opt in for this.

### TextPlayer
A player that can render any text. Text may be send via serial interface and persisted
in the internal eeprom. That text can be as long as 144 characters.

The Text player supports an ASCII subset with the characters from 0x20 (space) to 0x5F
(underscore). So only capital letters are supported. A text must be set all upper
case. Unsupported characters are rendered as a square.

The following characters from the ISO 8859-1/Windows-1252 codepage are also supported:


Code  | Char
----- | -----
0xC4  | Ä
0xD6  | Ö
0xDC  | Ü
0xA9  | (c)

Note that the copyright renders as a smiley :-)

The command for sending a new text starts with a *t* and must end with a *~*.
This looks as follows:

```
// tYOUR TEXT GOES HERE~
```


### programs.h

This file contains the array of all programs. A program entry consists of the
player and optinal configuration data.

# Sequences generation
There is a side project for designing the sequences that can be found [here][Sequencer].
It stores the sequences as a JSON file.
The _SequencePalletizer_ tool parses these files and generates a header file with
a palette and sequence C array from it. A PowerShell script does this for all
sequences in the _Sequences_ folder. The header files must then only be incorporated
in the _progams.h_.
A slightly different version of that tool, the _AlphabetCompiler_ is used to generate
the character bitmaps for the _TextPlayer_.

# License

The DanceFloor project is released under the [MIT License][opensource].

# Credits

[Adafruit WS2801 Library on GitHub][WS2801 Lib]

[Floating Point Autoscale Function by Paul Badger][fscale]

[Plasma code by bidouille][Plasma]

[Gaussian distribution class by Ivan Seidel Gomes][Gaussian]

[Sequencer]: https://github.com/angus42/dancefloor-sequencer
[Arduino]: http://www.arduino.cc/
[fscale]: http://playground.arduino.cc/Main/Fscale
[WS2801 Lib]: https://github.com/adafruit/Adafruit-WS2801-Library
[Plasma]: http://www.bidouille.org/prog/plasma
[Gaussian]: https://github.com/ivanseidel/Gaussian
[opensource]: http://www.opensource.org/licenses/MIT
