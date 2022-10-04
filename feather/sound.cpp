#include "sound.h"

int swapMusic(const char *musicPath){
	Mix_FreeMusic(currentMusic);
	currentMusic = Mix_LoadMUS(musicPath);
	Mix_PlayMusic(currentMusic, -1);
	return 0;
}

int pauseMusic(){
	Mix_PauseMusic();
	return 0;
}

int resumeMusic(){
	Mix_ResumeMusic();
	return 0;
}

/* int playSound(const char *soundPath){ */
/*  	Mix_PlayChannel(-1, Mix_LoadWAV(soundPath), 0); */
/*  	return 0; */
/* } */
