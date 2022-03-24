#pragma once

#include <iostream>

class My_time
{
private:
	int hour;
	int minute;
	int second;
public:
	//конструктор по умолчанию
	My_time() : hour(0), minute(0), second(0){}
	My_time(int h, int m, int s) : hour(h), minute(m), second(s) {}
	//конструктор копирования
	My_time(const My_time& tmp) : hour(tmp.hour), minute(tmp.minute), second(tmp.second) {}
	My_time& operator=(const My_time& tmp);
	My_time& operator+=(const My_time& tmp);
	friend std::ostream& operator<< (std::ostream& out, const My_time& t);
	int gethour() const { return hour; }
	int getminute() const { return minute; }
	int getsecond() const { return second; }
};

