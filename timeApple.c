#ifdef _APPLE_

#include "timeApple.h"
#include <mach/mach_time.h>
#include <stdint.h>

long long freq_num, freq_denom, tick_value, prev_tick_value;

void startTimer()
{
	mach_timebase_info_data_t tb;

	if (mach_timebase_info(&tb) == KERN_SUCCESS && tb.denom != 0) {
		freq_num = (long long)tb.numer;
		freq_denom = (long long)tb.denom;
	}

	prev_tick_value = mach_absolute_time();
}

long long tiempoPasado() {
	tick_value = mach_absolute_time();

	long long value_diff = tick_value - prev_tick_value;

	/* To prevent overflow */
	value_diff /= 1000;

	value_diff *= freq_num;
	value_diff /= freq_denom;

	return value_diff;
}

#endif