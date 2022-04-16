#pragma once
#include "vector.h"
#include "point.h"
#include <iostream>

using namespace std;

class Points : public vector 
{
public:
    //в конструкторе указываем, что создается два элемента в массиве 
    Points(int index=0) : vector(index*2) {}
    //конструктор копирования не наследуем
    Points(const Points& tmp) : vector((const vector&)tmp) {}
    ~Points() { }
    //размер вектора
    int size() const { return vector::len / 2; }
    //перегрузка []
    My_point operator [] (int index);

    const My_point operator [] (const int index) const;
    //присваивание
    void set(int index, const My_point& tmp);
    ////удаление
    //void del(int index);
    //Добавление в конец массива
    void add(int vx, int vy);
    ////сложение
    //Points& operator+=(Points& tmp);
    ////вычитание
    //Points& operator-=(Points& tmp);

    friend ostream& operator<< (std::ostream& out, const Points& r);

};