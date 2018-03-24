#ifndef MEASURE_TIME_H

#define MEASURE_TIME_H

#ifdef _WIN32
#include <Windows.h>
extern LARGE_INTEGER tcounter, freq, tick_value, prev_tick_value;
extern long long usecs;
#elif defined(__APPLE__)
#include "timeApple.h"
#include <mach/mach_time.h>
#include <stdint.h>
extern uint64_t freq_num, freq_denom, tick_value, prev_tick_value;
#elif defined(__linux__)
#include <time.h>
#include <sys/time.h>
#include <stdint.h>
extern long long prevTime, timeSpent;
#endif

void startTimer();

long long getTime();

#endif
