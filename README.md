# Feather Engine

**CURRENTLY IN EARLY ALPHA. THE ENGINE IS SUBJECT TO CHANGE, AND BUGS MAY BE VERY COMMON.**

A simple, lightweight, open-source C++ game engine

It currently has full rendering, text, input, sound, and physics systems set up, although it is still in active development, so things may be changed, added, or removed.

## Installing

To use the Feather Engine, just clone this git repo (it acts as a template). Make sure you remove this README file. From there, just start editing *game.cpp* and *PROJECT.h*. Have Fun, and if you make something cool, send it to **kadamlita@proton.me** to have it featured here.

## Technology

This project uses SDL2/OpenGL for access to input and graphics hardware and SCons as a buildsystem. You will need to install SCons yourself through pip, however I am considering shipping scons-local as part of the project.

## Developers

This project is developed by me (Adamek-K) in my spare time. Feel free to open a PR or make an issue if you wish to contribute! 

If you do contribute, you may place your name/username here

- Adamek-K (aka IAMACAR)
- BoogeyMan
- drakemj

## Documentation

Documentation is available in the docs/ directory. I may also make a tutorial when I have some time (if you wish to make a tutorial, go ahead and tell me, I will link it here). There is also an example project available in example/

## Building

The project uses SCons as its buildsystem. Just run scons and it should compile fine. You can install scons through pip if you don't have it.

## Funding & Sponsors

If you wish to contribute to the development of feather but have no programming experience, you can contribute to the project by donating. [donation link will go here]. If you do donate or support the project, you will be considered a sponsor and your name will be listed below. Thanks in advance!

## Shipping a game

Shipping a game is still a WIP.

## Planned Features

As features are introduced and planned, they will appear here. Not all features listed here will make it into the final engine, nor will every future feature be listed here. **If you are looking to contribute to development, this could be a good place to start**.

- A more advanced collision system
- Game compiling system (a way to actually ship games)
- Levels (like scenes in other engines)
- Entity grouping
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
- More advanced input (key release and key press functions, as well as support for more keys)
- Higher quality documentation & documentation translations
- Different sizes of text and custom font loading
- More advanced debugging inside the engine, such as returning an error when a sound is not found (similar to what is done for images currently). A debug mode (with a gui!) is currently being worked on.
- Finished documentation
- Updating the example project to showcase all features.

If you want to suggest a feature, open an issue.

## Known Bugs

These are bugs, both major and minor, that I am aware of and working on fixing. This could be another good place to get started if you are looking to contribute.

- playSound() may not work, depending on your platform.
- Crash() fails to produce any color on Windows.
- Collision on RigidEntities is a little bit wonky.
