#pragma once
#include "vector.h"
#include "time.h"

class arrtime :
    public vector
{
public:
    //в конструкторе указываем, что создается три элемента в массиве 
    arrtime(int index=0) : vector(index*3) {}
    //конструктор копирования не наследуем
    arrtime(const arrtime& tmp) : vector((const vector&)tmp) {}
    //размер вектора
    int size() const { return vector::size() / 2; }
    //перегрузка []
    time operator [] (int index);
    //присваивание
    void set(int index, const time& tmp);
    //сложение
    arrtime& operator+=(arrtime& tmp);
};

