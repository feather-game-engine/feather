#ifndef CORE_H
#define CORE_H

#ifdef _WIN32
#include "../include/Windows/SDL2/SDL.h"
#include "../include/Windows/SDL2/SDL_image.h"
#include "../include/Windows/SDL2/SDL_ttf.h"
#include "../include/Windows/SDL2/SDL_mixer.h"
#define SDL_main main
#else
#include "../include/Unix/SDL2/SDL.h"
#include "../include/Unix/SDL2/SDL_image.h"
#include "../include/Unix/SDL2/SDL_ttf.h"
#include "../include/Unix/SDL2/SDL_mixer.h"
#endif

#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

extern SDL_Window *win;
extern SDL_Renderer *rend;

extern bool running;

/* SDL_GLContext gl; */

extern SDL_Event event;

extern double delta;

extern int currentID;

extern bool drawHitboxes;

void Begin();
void Step();
void End();
#endif
