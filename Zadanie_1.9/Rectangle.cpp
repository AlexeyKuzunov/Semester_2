#include "Rectangle.h"
#include <stdlib.h>


MyRectangle::MyRectangle(const MyRectangle& r) {
    x = r.x;
    y = r.y;
    height = r.height;
    width = r.width;
}

MyRectangle::~MyRectangle() {

}

MyRectangle MyRectangle::operator-(const MyRectangle& r) {
    MyRectangle t = *this;
    t.x = x - r.x;
    t.y = y - r.y;
    t.height = height - r.height;
    t.width = width - r.width;
    return t;
}

MyRectangle MyRectangle::operator+(const MyRectangle& r) {
    MyRectangle t = *this;
    t.x = x + r.x;
    t.y = y + r.y;
    t.height = height + r.height;
    t.width = width + r.width;
    return t;
}

MyRectangle operator*(const MyRectangle& t, double d) {
    MyRectangle tmp;
    tmp.x = t.x * d;
    tmp.y = t.y * d;
    tmp.height = t.height * d;
    tmp.width = t.width * d;
    return tmp;
}

MyRectangle operator/(const MyRectangle& t, double d) {
    MyRectangle tmp;
    tmp.x = t.x / d;
    tmp.y = t.y / d;
    tmp.height = t.height / d;
    tmp.width = t.width / d;
    return tmp;
}

std::ostream& operator<< (std::ostream& out, const MyRectangle& r) {
    for (int i = 0; i < abs(r.height - r.y); i++) {
        //if (i == 0) out << "|";
        for (int j = 0; j < abs(r.width - r.x); j++) {
            if (j == 0) out << "_";

            //out << "*";
        }
        //out << "\n";
    }
    return out;
}

std::istream& operator>> (std::istream& in, MyRectangle& p) {
    std::cout << "Координата Х (Любое число не равное 0):";
    in >> p.x;
    if (!in) std::cerr << "Error x";
    std::cout << "Координата y (Любое число не равное 0):";
    in >> p.y;
    if (!in) std::cerr << "Error y";
    std::cout << "Высота прямоугольника (Любое число):";
    in >> p.height;
    if (!in) std::cerr << "Error height";
    std::cout << "Ширина прямоугольника (Любое число):";
    in >> p.width;
    if (!in) std::cerr << "Error width";    
    return in;
}

MyRectangle MyRectangle::operator+=(const MyRectangle& t)
{
    x = x + t.x;
    y = y + t.y;
    height = height + t.height;
    width = width + t.width;
    return MyRectangle();
}

MyRectangle MyRectangle::operator-=(const MyRectangle& t)
{
    x = x - t.x;
    y = y - t.y;
    height = height - t.height;
    width = width - t.width;
    return MyRectangle();
}
