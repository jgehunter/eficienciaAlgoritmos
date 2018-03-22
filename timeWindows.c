#include "timeWindows.h"
#include <Windows.h>

long long tcounter, freq, tick_value, prev_tick_value;

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

	long long usecs = (tick_value - prev_tick_value) / (freq / 1000000);

	return usecs;
}