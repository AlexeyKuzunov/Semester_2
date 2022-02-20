#pragma once

#include <iostream>

using namespace std;

class MyRectangle
{
	int height, width;
public:
	MyRectangle(int nheight = 0, int nwidth = 0): height(nheight), width(nwidth){} //конструктор
	MyRectangle(const MyRectangle& r); //конструктор копирования
	~MyRectangle();  //деструктор
	MyRectangle operator-(const MyRectangle& r);
	MyRectangle operator+(const MyRectangle& r);
	MyRectangle operator*(double d);
	MyRectangle operator/(double d);
	MyRectangle operator+=(const MyRectangle& t);
	MyRectangle operator-=(const MyRectangle& t);
	MyRectangle operator=(const MyRectangle& p) { height = p.height; width = p.width; return *this; }
	friend ostream& operator<< (std::ostream& out, const MyRectangle& r);
	friend istream& operator>> (std::istream& in, MyRectangle& r);
};

