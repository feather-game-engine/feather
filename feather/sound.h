#ifndef SOUND_H
#define SOUND_H
#include "core.h"

extern Mix_Music *currentMusic;

int swapMusic(const char *musicPath);

int pauseMusic();
int resumeMusic();

/* int playSound(const char *soundPath); */

#endif
