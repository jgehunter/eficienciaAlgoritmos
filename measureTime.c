#include "measureTime.h"

#ifdef _WIN32
#include <Windows.h>
#elif defined(__APPLE__)
#include <stdint.h>
#include <mach/mach_time.h>
#elif defined(__linux__)
#include <time.h>
#include <sys/time.h>
#include <stdint.h>
#else
#error "Este SO no esta soportado"
#endif

#ifdef _WIN32
LARGE_INTEGER tcounter, freq, tick_value, prev_tick_value;
long long usecs;
#elif defined(__APPLE__)
uint64_t freq_num, freq_denom, tick_value, prev_tick_value;
#elif defined(__linux__)
long long prevTime, timeSpent;
#endif

void startTimer() {
#ifdef _WIN32
	if (QueryPerformanceFrequency(&tcounter) != 0) {
		freq = tcounter;
	}

	if (QueryPerformanceCounter(&tcounter) != 0) {
		prev_tick_value = tcounter;
	}
#elif defined(__APPLE__)
	mach_timebase_info_data_t tb;

	if (mach_timebase_info(&tb) == KERN_SUCCESS && tb.denom != 0) {
		freq_num = tb.numer;
		freq_denom = tb.denom;
}

	prev_tick_value = mach_absolute_time();
#elif defined(__linux__)
	struct timespec ts;

	if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0)
		prevTime = (long long)(ts.tv_sec * 1000000 + ts.tv_nsec / 1000);
	else
		prevTime = 0;
#endif
}

long long getTime() {
#ifdef _WIN32
	if (QueryPerformanceCounter(&tcounter) != 0) {
		tick_value = tcounter;
	}

	usecs = (tick_value.QuadPart - prev_tick_value.QuadPart) / (freq.QuadPart / 1000000);

	return usecs;
#elif defined(__APPLE__)
	tick_value = mach_absolute_time();

	uint64_t value_diff = tick_value - prev_tick_value;

	/* To prevent overflow */
	value_diff /= 1000;

	value_diff *= freq_num;
	value_diff /= freq_denom;

	return (long long)(value_diff);
#elif defined(__linux__)
	struct timespec ts;

	if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0)
		timeSpent = (long long)(ts.tv_sec * 1000000 + ts.tv_nsec / 1000);
	else
		prevTime = 0;

	long long timeDiff = timeSpent - prevTime;

	return timeDiff;
#endif
}
	
