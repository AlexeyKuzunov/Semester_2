#include "arrtime.h"

time arrtime::operator [] (int index) {
	return time(v[index * 3], v[index * 3 + 1], v[index * 3 + 2]);
}

void arrtime::set(int index, const time& tmp) {
	v[index * 3] = tmp.gethour();
	v[index * 3 + 1] = tmp.getminute();
	v[index * 3 + 2] = tmp.getsecond();
}

arrtime& arrtime::operator+=(arrtime& tmp) {
	if (len < tmp.len) {
		for (int i = 0; i < tmp.len / 3; i++) {
			v[3 * i] += tmp.v[3 * i];
			v[3 * i + 1] += tmp.v[3 * i + 1];
			v[3 * i + 2] += tmp.v[3 * i + 2];
			return *this;
		}
	}
	else {
		for (int i = 0; i < len / 3; i++) {
			v[3 * i] += tmp.v[3 * i];
			v[3 * i + 1] += tmp.v[3 * i + 1];
			v[3 * i + 2] += tmp.v[3 * i + 2];
			return *this;
		}
	}
	
}
