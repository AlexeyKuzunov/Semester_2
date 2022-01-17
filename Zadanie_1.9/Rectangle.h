#pragma once

#include <iostream>

using namespace std;

class MyRectangle
{
	int x, y, height, width;
	static void Plot(int x1, int y1, int x2, int y2);
public:
	MyRectangle(int nx = 0, int ny = 0, int nheight = 0, int nwidth = 0): x(nx), y(ny), height(nheight), width(nwidth){} //конструктор
	MyRectangle(const MyRectangle& r); //конструктор копирования
	~MyRectangle();  //деструктор
	MyRectangle operator-(const MyRectangle& r);
	MyRectangle operator+(const MyRectangle& r);
	friend MyRectangle operator*(const MyRectangle& t, double d);
	friend MyRectangle operator/(const MyRectangle& t, double d);
	MyRectangle operator+=(const MyRectangle& t);
	MyRectangle operator-=(const MyRectangle& t);
	MyRectangle operator=(const MyRectangle& p) { x = p.x; y = p.y; height = p.height; width = p.width; return *this; }
	friend ostream& operator<< (std::ostream& out, const MyRectangle& r);
	friend istream& operator>> (std::istream& in, MyRectangle& r);
};

