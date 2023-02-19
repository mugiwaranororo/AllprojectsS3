## Getting Started with SDL2

## Prerequisites

In the Makefile, yoou will just need a flag:
`pkg-config --cflags sdl2`
And you need to install the SDL2 library:
`sudo apt-get install libsdl2-dev`
a thing like this
AND THAT'S ALL

## Introduce to SDL2

It is decomposed into 3 parts:
- The display
- The event loop
- The main

In the main: You init the SDL, you create the window, the renderer, the texture, the surface
You call the event loop
You destroy the window, the renderer, the texture, the surface

In the event loop: You wait for an event to happen
like a key pressed, a mouse moved, a window resized, etc.

In the display: You update the texture with the surface that can take in parameter the event that happened in the event loop