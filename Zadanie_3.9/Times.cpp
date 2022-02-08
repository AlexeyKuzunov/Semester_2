#include "times.h"

int times::hours(int index) {
	return v[index * 3];
}

int times::minutes(int index) {
	return v[index * 3 + 1];
}

int times::seconds(int index) {
	return v[index * 3 + 2];
}

int& times::operator [] (const int index) {
	return hours(index)*10000 + minutes(index)*100 + seconds(index);
}