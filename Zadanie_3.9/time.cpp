#include "time.h"

My_time& My_time::operator=(const My_time& tmp) {
	hour = tmp.hour;
	minute = tmp.minute;
	second = tmp.second;
	return *this;
}

My_time& My_time::operator+=(const My_time& tmp)
{
	hour += tmp.hour;
	minute += tmp.minute;
	second += tmp.second;
	return *this;
}

std::ostream& operator<< (std::ostream& out, const My_time& t) {
	// Поскольку operator<< является другом класса My_time, то мы имеем прямой доступ к членам My_time
	out << t.hour << ":" << t.minute << ":" << t.second;
	return out;
}