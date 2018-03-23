#ifdef __APPLE__

#ifndef TIME_APPLE_H
#define TIME_APPLE_H

extern long long tcounter, freq, tick_value;

void startTimer(void);

long long tiempoPasado(void);

#endif
#endif
