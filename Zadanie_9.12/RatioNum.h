#pragma once

#include <iostream>
#include <complex>

class RatioNum
{
private:
	int num; //числитель
	int denom; //знаменатель
public: 
    RatioNum(int num_ = 0, int denom_ = 1) : num(num_), denom(denom_){
        if (!denom)
            throw std::invalid_argument("Знаменатель не может быть равен нулю");
        if (((num >> (sizeof(num) * 8 - 1)) ^ (denom >> (sizeof(denom) * 8 - 1))) & 1)
            num = -std::abs(num);
        else
            num = std::abs(num);
        denom = std::abs(denom);
    };
    friend RatioNum const operator+ (RatioNum const&, RatioNum const&);
    friend RatioNum const operator- (RatioNum const&, RatioNum const&);
    friend RatioNum const operator* (RatioNum const&, RatioNum const&);
    friend RatioNum const operator/ (RatioNum const&, RatioNum const&);
    RatioNum operator= (RatioNum const&); //присваивание другой дроби
    RatioNum operator= (int const&); //присваивание целого числа

    friend std::ostream& operator<< (std::ostream&, RatioNum const&);
    friend std::istream& operator>> (std::istream&, RatioNum&);
    double toReal(); //приведение типа к вещественному числу
    std::complex<double> toComplex();
};

