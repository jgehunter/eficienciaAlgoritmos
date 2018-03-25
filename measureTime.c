/*
*	FICHERO: measureTime.c
*	AUTORES: Jorge Hunter	Iñaki Echevarría	José Miguel Hervás
*
*	Funciones que se utilizan para medir el tiempo de ejecución. Solo se compila
* la versión que corresponda al sistema operativo del usuario.
*/

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
#error "Su SO no está soportado"
#endif

#ifdef _WIN32
LARGE_INTEGER tcounter;
LARGE_INTEGER freq;
LARGE_INTEGER tick_value;
LARGE_INTEGER prev_tick_value;
long long usecs;
#elif defined(__APPLE__)
uint64_t freq_num;
uint64_t freq_denom;
uint64_t tick_value;
uint64_t prev_tick_value;
#elif defined(__linux__)
long long prevTime;
long long timeSpent;
#endif

#ifdef _WIN32
void startTimer() 
{
	if (QueryPerformanceFrequency(&tcounter) != 0) {
		freq = tcounter;
	}

	if (QueryPerformanceCounter(&tcounter) != 0) {
		prev_tick_value = tcounter;
	}
}
#endif

#ifdef __APPLE__
void startTimer() 
{
	mach_timebase_info_data_t tb;

	if (mach_timebase_info(&tb) == KERN_SUCCESS && tb.denom != 0) {
		freq_num = tb.numer;
		freq_denom = tb.denom;
	}

	prev_tick_value = mach_absolute_time();
}
#endif

#ifdef __linux__
void startTimer() 
{
	struct timespec ts;

	if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0)
		prevTime = (long long)(ts.tv_sec * 1000000 + ts.tv_nsec / 1000);
	else
		prevTime = 0;
}
#endif

#ifdef _WIN32
long long getTime()
{
	if (QueryPerformanceCounter(&tcounter) != 0) {
		tick_value = tcounter;
	}

	usecs = (tick_value.QuadPart - prev_tick_value.QuadPart) / (freq.QuadPart / 1000000);

	return usecs;
}
#endif

#ifdef __APPLE__
long long getTime()
{
	tick_value = mach_absolute_time();

	uint64_t value_diff = tick_value - prev_tick_value;

	value_diff /= 1000;

	value_diff *= freq_num;
	value_diff /= freq_denom;

	return (long long)(value_diff);
}
#endif

#ifdef __linux__
long long getTime()
{
	struct timespec ts;

	if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0)
		timeSpent = (long long)(ts.tv_sec * 1000000 + ts.tv_nsec / 1000);
	else
		prevTime = 0;

	long long timeDiff = timeSpent - prevTime;

	return timeDiff;
}
#endif
	
