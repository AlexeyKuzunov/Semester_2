#include "time.h"

time& time::operator=(const time& tmp) {
	hour = tmp.hour;
	minute = tmp.minute;
	second = tmp.second;
	return *this;
}

time& time::operator+=(const time& tmp)
{
	hour += tmp.hour;
	minute += tmp.minute;
	second += tmp.second;
	return *this;
}
