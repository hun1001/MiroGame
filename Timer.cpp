#include "Timer.h"

void Timer::Start()
{
	_timer = time(NULL);
	localtime_s(&t, &_timer);
	_stime = _timer;
}

void Timer::Stop()
{
	_timer = time(NULL);
	_etime = _timer;
	_interval = _etime - _stime;
}

long long Timer::GetInterval()
{
	return _interval;
}
