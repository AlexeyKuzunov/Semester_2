#pragma once

#include "My_Vector.h"

class times :
    public My_Vector
{
public:
    //Конструкторы
    times(int N = 0) : My_Vector(N*3){}
    times(const times& tmp) : My_Vector((const My_Vector&)tmp) {}
    //Размер  
    int size() const { return My_Vector::size() / 3; }

    My_Vector operator [] (int index);

};

