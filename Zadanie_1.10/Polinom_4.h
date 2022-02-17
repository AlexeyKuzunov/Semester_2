#pragma once

#include <stdio.h>
#include <iostream>

using namespace std;

class Polinom {
private:
    double a, b, c, d, e; //коэффициенты полинома 4-й степени
public:
    Polinom(double na = 0.0, double nb = 0.0, double nc = 0.0, double nd = 0.0, double ne = 0.0) : a(na), b(nb), c(nc), d(nd), e(ne) {} //конструктор
    ~Polinom();  //деструктор
    Polinom(const Polinom& p); //конструктор копирования
    Polinom operator-(const Polinom& t);
    Polinom operator+(const Polinom& t);
    friend Polinom operator*(const Polinom& t, double d);
    friend Polinom operator/(const Polinom& t, double d);
    friend Polinom operator+=(const Polinom& t, double d);
    friend Polinom operator-=(const Polinom& t, double d);
    Polinom operator=(const Polinom& p) { a = p.a; b = p.b; c = p.c; d = p.d; e = p.e; return *this; }
    friend ostream& operator<< (std::ostream& out, const Polinom& p);
    friend istream& operator>> (std::istream& in, Polinom& p);
};
