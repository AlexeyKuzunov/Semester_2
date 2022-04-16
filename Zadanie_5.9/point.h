#pragma once

#include <iostream>

class My_point
{
private:
	int x;
	int y;
public:
	//конструктор по умолчанию
	My_point() : x(0), y(0){}
	My_point(int x_0, int y_0) : x(x_0), y(y_0){}
	//конструктор копирования
	My_point(const My_point& tmp) : x(tmp.x), y(tmp.y) {}
	//My_time& operator=(const My_time& tmp);
	//My_time& operator+=(const My_time& tmp);
	//friend std::ostream& operator<< (std::ostream& out, const My_time& t);
	int getx() const { return x; }
	int gety() const { return y; }
};