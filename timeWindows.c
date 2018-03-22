#ifdef _WIN32

#include "timeWindows.h"
#include <Windows.h>

LARGE_INTEGER tcounter, freq, tick_value, prev_tick_value;

void startTimer() {
	if (QueryPerformanceFrequency(&tcounter) != 0) {
		freq = tcounter;
	}

	if (QueryPerformanceCounter(&tcounter) != 0) {
		prev_tick_value = tcounter;
	}
}

long long tiempoPasado() {
	if (QueryPerformanceCounter(&tcounter) != 0) {
		tick_value = tcounter;
	}

	long long usecs = (tick_value.QuadPart - prev_tick_value.QuadPart) / (freq.QuadPart / 1000000);

	return usecs;
}

#endif