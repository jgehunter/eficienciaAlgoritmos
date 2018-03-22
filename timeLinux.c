#ifdef _linux_
#include <time.h>
#include <sys/time.h>
#include <stdint.h>

long long prevTime, time;

void startTimer()
{
	struct timespec ts;

	if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0)
		prevTime = (long long)(ts.tv_sec * 1000000 + ts.tv_nsec / 1000);
	else
		prevTime = 0;
}

long long tiempoPasado() {
	struct timespec ts;

	if (clock_gettime(CLOCK_MONOTONIC, &ts) == 0)
		time = (long long)(ts.tv_sec * 1000000 + ts.tv_nsec / 1000);
	else
		prevTime = 0;

	long long timeDiff = time - prevTime;

	return timeDiff;
}
#endif