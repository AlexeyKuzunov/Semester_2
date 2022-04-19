#pragma once

#include <iostream>
#include <math.h>

class My_point
{
private:
	double x;
	double y;
public:
	//конструктор по умолчанию
	My_point() : x(0), y(0){}
	My_point(double x_0, double y_0) : x(x_0), y(y_0){}
	//конструктор копирования
	My_point(const My_point& tmp) : x(tmp.x), y(tmp.y) {}
	//My_time& operator=(const My_time& tmp);
	//My_time& operator+=(const My_time& tmp);
	//friend std::ostream& operator<< (std::ostream& out, const My_time& t);
	double getx() const { return x; }
	double gety() const { return y; }
	void add(double tmpy) { y += tmpy; }
	My_point& operator= (const My_point& tmp) { x = tmp.x; y = tmp.y; return *this; }
	friend My_point operator-(const My_point& tmp, const My_point& tmp1) { return My_point(fabs(tmp.x-tmp1.x), tmp.y - tmp1.y); }
};