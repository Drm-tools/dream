
#include "../../common/util/Pacer.h"

#include <signal.h>
#include <unistd.h>
#include <cstdio>
#include <iostream>

CPacer::CPacer(uint64_t ns)
{
	timespec now;
	int r = clock_gettime(CLOCK_REALTIME, &now);
	if(r<0)
		perror("time");
	interval = ns;
	timekeeper = 1000000000LL*now.tv_sec+now.tv_nsec;
	timekeeper += interval;
}

CPacer::~CPacer()
{
	cout << "CPacer destructor" << endl; cout.flush();
}

void CPacer::wait()
{
	uint64_t delay_ns = nstogo();
	if(delay_ns>20000000ULL)
	{
		timespec delay;
		delay.tv_sec = delay_ns / 1000000000ULL;
		delay.tv_nsec = delay_ns % 1000000000ULL;
		nanosleep(&delay, NULL);
	}
	timekeeper += interval;
}

uint64_t CPacer::nstogo()
{
	timespec now;
	clock_gettime(CLOCK_REALTIME, &now);
	uint64_t now_ns = 1000000000LL*now.tv_sec+now.tv_nsec;
	if(timekeeper<=now_ns)
		return 0;
	return timekeeper - now_ns;
}
