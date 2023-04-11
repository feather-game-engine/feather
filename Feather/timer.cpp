#include "timer.h"

Timer::Timer(Uint32 total, bool newOneshot){
	endTime = total;
	oneshot = newOneshot;
}

int Timer::Start(){
	startTime = SDL_GetTicks();
	return 0;
}
