#include "arrtime.h"

My_time ArrTime::operator [] (int index) {
	return My_time(v[index * 3], v[index * 3 + 1], v[index * 3 + 2]);
}

void ArrTime::set(int index, const My_time& tmp) {
	v[index * 3] = tmp.gethour();
	v[index * 3 + 1] = tmp.getminute();
	v[index * 3 + 2] = tmp.getsecond();
}

void ArrTime::del(int index) {
	for(int i = 0; i < 3;i++)
		erase(index * 3);
}

ArrTime& ArrTime::operator+=(ArrTime& tmp) {
	if (len < tmp.len) {
		for (int i = 0; i < (tmp.len / 3); i++) {
			v[3 * i] += tmp.v[3 * i];
			v[3 * i + 1] += tmp.v[3 * i + 1];
			v[3 * i + 2] += tmp.v[3 * i + 2];			
		}
		return *this;
	}
	else {
		for (int i = 0; i < len / 3; i++) {
			v[3 * i] += tmp.v[3 * i];
			v[3 * i + 1] += tmp.v[3 * i + 1];
			v[3 * i + 2] += tmp.v[3 * i + 2];			
		}
		return *this;
	}
	
}

ArrTime& ArrTime::operator-=(ArrTime& tmp)
{
	if (len > tmp.len) {
		for (int i = 0; i < tmp.len / 3; i++) {
			v[3 * i] -= tmp.v[3 * i];
			v[3 * i + 1] -= tmp.v[3 * i + 1];
			v[3 * i + 2] -= tmp.v[3 * i + 2];			
		}
		return *this;
	}
	else {
		for (int i = 0; i < len / 3; i++) {
			v[3 * i] -= tmp.v[3 * i];
			v[3 * i + 1] -= tmp.v[3 * i + 1];
			v[3 * i + 2] -= tmp.v[3 * i + 2];			
		}
		return *this;
	}
}
