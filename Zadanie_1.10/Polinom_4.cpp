#include "Polinom_4.h"

Polinom::~Polinom(){

}

Polinom::Polinom(const Polinom& p){
    a = p.a;
    b = p.b;
    c = p.c;
    d = p.d;
    e = p.e;
}

Polinom Polinom::operator-(const Polinom& p){
    Polinom tmp = *this;
    tmp.a = a - p.a;
    tmp.b = b - p.b;
    tmp.c = c - p.c;
    tmp.d = d - p.d;
    tmp.e = e - p.e;
    return tmp;
}

Polinom Polinom::operator+(const Polinom& p){
    Polinom tmp = *this;
    tmp.a = a + p.a;
    tmp.b = b + p.b;
    tmp.c = c + p.c;
    tmp.d = d + p.d;
    tmp.e = e + p.e;
    return tmp;
}

Polinom operator*(const Polinom& t, double d){
    Polinom tmp;
    tmp.a = t.a * d;
    tmp.b = t.b * d;
    tmp.c = t.c * d;
    tmp.d = t.d * d;
    tmp.e = t.e * d;
    return tmp;
}

Polinom operator/(const Polinom& t, double d){
    Polinom tmp;
    tmp.a = t.a / d;
    tmp.b = t.b / d;
    tmp.c = t.c / d;
    tmp.d = t.d / d;
    tmp.e = t.e / d;
    return tmp;
}

Polinom operator+=(const Polinom& t, double d){
    Polinom tmp;
    tmp.a = t.a + d;
    tmp.b = t.b + d;
    tmp.c = t.c + d;
    tmp.d = t.d + d;
    tmp.e = t.e + d;
    return tmp;
}

Polinom operator-=(const Polinom& t, double d){
    Polinom tmp;
    tmp.a = t.a - d;
    tmp.b = t.b - d;
    tmp.c = t.c - d;
    tmp.d = t.d - d;
    tmp.e = t.e - d;
    return tmp;
}

std::ostream& operator<< (std::ostream& out, const Polinom& p){
    if ((p.a == 0) || (p.b == 0)) { std::cerr << "Error b"; }
    else {
        out << p.a << "X^4";
        if (p.b > 0) out << "+";
        out << p.b << "X^3";

        if (p.c != 0){
            if (p.c > 0) out << "+";
            out << p.c << "X^2";
        }

        if (p.d > 0) out << "+";
        if (p.d == 0) { out << "X"; }
        else out << p.d << "X";

        if (p.e != 0){
            if (p.e > 0){
                out << "+";
            }
            out << p.e;
        }
    }
    return out;
}

std::istream& operator>> (std::istream& in, Polinom& p){
    std::cout << "Коэффициент для Х^4 (Любое число не равное 0):";
    in >> p.a;
    if (!in) std::cerr << "Error a";
    std::cout << "Коэффициент для Х^3 (Любое число не равное 0):";
    in >> p.b;
    if (!in) std::cerr << "Error b";
    std::cout << "Коэффициент для Х^2 (Любое число):";
    in >> p.c;
    if (!in) std::cerr << "Error c";
    std::cout << "Коэффициент для Х (Любое число):";
    in >> p.d;
    if (!in) std::cerr << "Error d";
    std::cout << "Любое число:";
    in >> p.e;
    if (!in) std::cerr << "Error e";
    return in;
}