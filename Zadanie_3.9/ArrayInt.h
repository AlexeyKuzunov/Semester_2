#pragma once

#include <cassert> // для assert()

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
    // Функция reallocate() изменяет размер массива. 
    //Все существующие элементы внутри массива будут уничтожены.
    //Процесс быстрый 
    void reallocate(int newLength);
    // Функция resize() изменяет размер массива. 
    //Все существующие элементы сохраняются. Процесс медленный
    void resize(int newLength);
    void erase();
    void insertBefore(int value, int index);
    void remove(int index);
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
};

