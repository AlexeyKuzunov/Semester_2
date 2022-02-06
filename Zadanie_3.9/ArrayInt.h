#pragma once

#include <cassert> // ��� assert()

class ArrayInt {
private:
    int m_length;
    int* m_data;
protected:

public:
    ArrayInt() : m_length(0), m_data(nullptr) {}
    ArrayInt(int length);
    ~ArrayInt();
    int& operator[](int index);
    int getLength();
    // ������� reallocate() �������� ������ �������. 
    //��� ������������ �������� ������ ������� ����� ����������.
    //������� ������� 
    void reallocate(int newLength);
    // ������� resize() �������� ������ �������. 
    //��� ������������ �������� �����������. ������� ���������
    void resize(int newLength);
    void erase();
    void insertBefore(int value, int index);
    void remove(int index);
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
};

