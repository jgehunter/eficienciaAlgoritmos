#ifndef TIME_WINDOWS_H
#define TIME_WINDOWS_H

#include <Windows.h>

extern long long tcounter, freq, tick_value;

void startTimer();

long long tiempoPasado();

#endif
