# Feather Engine

**CURRENTLY IN EARLY ALPHA. THE ENGINE IS SUBJECT TO CHANGE, AND BUGS MAY BE VERY COMMON.**

A simple, lightweight, open-source C++ game engine

It currently has full rendering, text, input, sound, and collision systems set up, although it is still in active development, so things may be changed, added, or removed.

## Installing

To use the Feather Engine, just clone this git repo (it acts as a template). Make sure you remove this README file. From there, just start editing *game.cpp* and *PROJECT.h*. Have Fun, and if you make something cool, send it to **kadamlita@proton.me** to have it featured here.

## Technology

This project uses SDL2/OpenGL for access to input and graphics hardware. SDL is planned to be included in this template. Building this project is still a bit tough, as I am still experimenting with buildsystems. I hope to be able to get something worked out soon. If you find something that works well with the engine, feel free to either open an issue or open a PR implementing it yourself.

## Developers

This project is developed by me in my spare time. Feel free to open a PR or make an issue if you wish to contribute! 

If you do contribute, you may place your name/username here

- Adamek-K

## Documentation

Documentation is available in the docs/ directory. I may also make a tutorial when I have some time (if you wish to make a tutorial, go ahead and tell me, I will link it here). There is also an example project available in example/

## Building

Building/compiling the engine is still a little difficult, as you will need bring your own buildsystem. The files you need to compile are *game.cpp*, *feather/main.cpp*, *feather/entity.cpp*, *feather/input.cpp*, *feather/sound.cpp*, *feather/debug.cpp*, *feather/util.cpp*, and *feather/text.cpp*. You will also need to link SDL2, SDL2_image, SDL2_mixer, and SDL2_ttf, all of which will be available in the include/ directory in the near future. An example Makefile is included in the project.

## Funding & Sponsors

If you wish to contribute to the development of feather but have no programming experience, you can contribute to the project by donating. [donation link will go here]. If you do donate or support the project, you will be considered a sponsor and your name will be listed below. Thanks in advance!

## Shipping a game

Shipping a game is still a WIP. For now, you can run make ship to create a basic folder holding all the necessary things.

## Planned Features

As features are introduced and planned, they will appear here. Not all features listed here will make it into the final engine, nor will every future feature be listed here. **If you are looking to contribute to development, this could be a good place to start**.

- A more advanced collision system
- Game compiling system (a way to actually ship games)
- Levels (like scenes in other engines)
- Entity tagging
- A view (camera) system
- A more modular design, and support for external modules
- A timing system
- More options in PROJECT.h
- Window resizing (game scales with it) & fullscreen windows
- Simple serialization (saving & loading funcs)
- Textbox Input
- Better structure for projects (easier to work with more than one file)
- Automatic assets/ injection into asset paths. (type "player.png" instead of "assets/player.png")
- Simple GUI, or at least some small helper utilities
- Basic rotation
- More advanced input (key release and key press functions, as well as support for more keys)
- Higher quality documentation & documentation translations
- Different sizes of text and custom font loading
- More advanced debugging inside the engine, such as returning an error when a sound is not found (similar to what is done for images currently)
- Finished documentation
- A simple physics system
- Entity instancing/cloning (similar to Instantiate() in Unity3D)
- Updating the example project to showcase all features.

If you want to suggest a feature, open an issue.

## Known Bugs

These are bugs, both major and minor, that I am aware of and working on fixing. This could be another good place to get started if you are looking to contribute.
