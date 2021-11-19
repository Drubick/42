#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include "philosophers.h"

#include "philosophers.h"

long	get_time(void)
{
	struct timeval	tv;
	long			time_in_ms;

	gettimeofday(&tv, NULL);
	time_in_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time_in_ms);
}