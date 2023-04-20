#ifndef TIMER_H
#define TIMER_H
#include "core.h"

class Timer{
	private:
		bool active;
		Uint32 startTime;
		Uint32 endTime;
	public:
		bool oneshot;

		Timer(Uint32 total, bool newOneshot = false);
		int Start();
		bool isFinished();
};

#endif
