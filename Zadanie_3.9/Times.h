#pragma once

#include "My_Vector.h"

class times :
    public My_Vector
{
public:
    //Конструкторы
    times(int N = 0) : My_Vector(N*3){}
    times(const times& tmp) : My_Vector((const My_Vector&)tmp) {}
    //Количество троек чисел 
    int size() const { return My_Vector::size() / 3; }

    int hours(int index);
    int minutes(int index);
    int seconds(int index);

    int& operator [] (const int index);

};

