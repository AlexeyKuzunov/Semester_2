#include "Rectangle.h"
#include <stdlib.h>

using namespace std;

MyRectangle::MyRectangle(const MyRectangle& r) {
    height = r.height;
    width = r.width;
}

MyRectangle::~MyRectangle() {

}

MyRectangle MyRectangle::operator-(const MyRectangle& r) {
    MyRectangle t = *this;
    t.height = height - r.height;
    t.width = width - r.width;
    return t;
}

MyRectangle MyRectangle::operator+(const MyRectangle& r) {
    MyRectangle t = *this;
    t.height = height + r.height;
    t.width = width + r.width;
    return t;
}

MyRectangle MyRectangle::operator*(double d) {
    MyRectangle tmp;
    tmp.height = height * d;
    tmp.width = width * d;
    return tmp;
}

MyRectangle MyRectangle::operator/(double d) {
    MyRectangle tmp;
    tmp.height = height / d;
    tmp.width = width / d;
    return tmp;
}

ostream& operator<< (std::ostream& out, const MyRectangle& r) {
    out << "Размеры прямоугольника: ";
    out << "(Высота: " << r.height << "; Ширина: " << r.width << ") ";
    return out;
}

std::istream& operator>> (std::istream& in, MyRectangle& p) {
    std::cout << "Высота прямоугольника: ";
    in >> p.height;
    if (!in) std::cerr << "Error height";
    std::cout << "Ширина прямоугольника: ";
    in >> p.width;
    if (!in) std::cerr << "Error width";    
    return in;
}

MyRectangle MyRectangle::operator+=(const MyRectangle& t)
{
    height = height + t.height;
    width = width + t.width;
    return MyRectangle();
}

MyRectangle MyRectangle::operator-=(const MyRectangle& t)
{
    height = height - t.height;
    width = width - t.width;
    return MyRectangle();
}
