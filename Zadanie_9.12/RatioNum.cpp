#include "RatioNum.h"
#include <sstream>

RatioNum const operator+(RatioNum const& lo, RatioNum const& ro)
{
	return RatioNum(lo.num * ro.denom + ro.num * lo.denom, lo.denom * ro.denom);;
}

RatioNum const operator-(RatioNum const& lo, RatioNum const& ro)
{
	return lo + RatioNum(-ro.num, ro.denom);;
}

RatioNum const operator*(RatioNum const& lo, RatioNum const& ro)
{
	return RatioNum(lo.num * ro.num, lo.denom * ro.denom);
}

RatioNum const operator/(RatioNum const& lo, RatioNum const& ro)
{
	return lo * RatioNum(ro.denom, ro.num);
}

std::ostream& operator<<(std::ostream& ost, RatioNum const& ro)
{
    ost << "(" << ro.num << "\\" << ro.denom << ")";
    return ost;
}

std::istream& operator>>(std::istream& ist, RatioNum& r)
{
    std::string s;
    std::getline(ist, s, ')');
    std::string::size_type ind;
    while ((ind = s.find_first_of("(,)")) != std::string::npos)
        s.replace(ind, 1, 1, ' ');
    std::istringstream iss(s);
    iss >> r.num >> r.denom;
    if (!r.denom)
        throw std::invalid_argument("Знаменатель не может быть равен нулю");
    if (((r.num >> (sizeof(r.num) * 8 - 1)) ^ (r.denom >> (sizeof(r.denom) * 8 - 1))) & 1)
        r.num = -std::abs(r.num);
    else
        r.num = std::abs(r.num);
    r.denom = std::abs(r.denom);
    return ist;
}

RatioNum RatioNum::operator=(RatioNum const& ro)
{
    this->num = ro.num;
    this->denom = ro.denom;
    return *this;
}

RatioNum RatioNum::operator=(int const& value)
{
    this->num = value;
    this->denom = 1;
    return *this;
}

double RatioNum::toReal()
{    
    return ((double)this->num / (double)this->denom);
}

std::complex<double> RatioNum::toComplex()
{
    return std::complex<double>(toReal());
}
