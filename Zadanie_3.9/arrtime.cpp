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
	int h = 0, m = 0;
		for (int i = 0; i < (tmp.len / 3); i++) {
			//Плюсуем секунды
			v[3 * i + 2] += tmp.v[3 * i + 2];
			if (v[3 * i + 2] >= 60) {
				v[3 * i + 1] += 1;
				if (v[3 * i + 1] >= 60) {
					v[3 * i] += 1;
					v[3 * i + 1] -= 60;
				}
				v[3 * i + 2] -= 60;
			}
			//Плюсуем минуты
			v[3 * i + 1] += tmp.v[3 * i + 1];
			if (v[3 * i + 1] >= 60) {
				v[3 * i] += 1;
				v[3 * i + 1] -= 60;
			}
			//Плюсуем часы
			v[3 * i] += tmp.v[3 * i];

		}
		return *this;
}

ArrTime& ArrTime::operator-=(ArrTime& tmp)
{
	for (int i = 0; i < tmp.len / 3; i++) {
		//Минусуем секунды
		if (tmp.v[3 * i + 2] >= v[3 * i + 2]) {
			v[3 * i + 1] -= 1;
			v[3 * i + 2] = 0;
		}
		else
			v[3 * i + 2] -= tmp.v[3 * i + 2];
		//Минусуем минуты
		if (tmp.v[3 * i + 1] >= v[3 * i + 1]) {
			v[3 * i] -= 1;
			v[3 * i + 1] = 0;
		}
		else
			v[3 * i + 1] -= tmp.v[3 * i + 1];
		//Минусуем часы
		v[3 * i] -= tmp.v[3 * i];

					
		}
		return *this;
}
