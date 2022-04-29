#pragma once
#include "console.h"

class Timer
{
private:
	time_t _timer;
	struct tm t;
	long long _stime, _etime;
	long long _interval;
public:
	void Start();

	void Stop();

	long long GetInterval();
};

