#pragma once
#include "vector.h"
#include "time.h"

class arrtime :
    public vector
{
public:
    //� ������������ ���������, ��� ��������� ��� �������� � ������� 
    arrtime(int index=0) : vector(index*3) {}
    //����������� ����������� �� ���������
    arrtime(const arrtime& tmp) : vector((const vector&)tmp) {}
    //������ �������
    int size() const { return vector::size() / 2; }
    //���������� []
    time operator [] (int index);
    //������������
    void set(int index, const time& tmp);
    //��������
    arrtime& operator+=(arrtime& tmp);
};

