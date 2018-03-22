#ifndef TIME_LINUX_H
#define TIME_LINUX_H

extern long long tcounter, freq, tick_value;

void startTimer();

long long tiempoPasado();

#endif