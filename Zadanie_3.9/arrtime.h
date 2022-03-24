#pragma once
#include "vector.h"
#include "time.h"

class ArrTime : public vector 
{
public:
    //в конструкторе указываем, что создается три элемента в массиве 
    ArrTime(int index=0) : vector(index*3) {}
    //конструктор копирования не наследуем
    ArrTime(const ArrTime& tmp) : vector((const vector&)tmp) {}
    ~ArrTime() { }
    //размер вектора
    int size() const { return vector::size() / 3; }
    //перегрузка []
    My_time operator [] (int index);
    //присваивание
    void set(int index, const My_time& tmp);
    //удаление
    void del(int index);
    //сложение
    ArrTime& operator+=(ArrTime& tmp);
    //вычитание
    ArrTime& operator-=(ArrTime& tmp);

};

