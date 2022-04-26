﻿/*
Создать шаблонную очередь mydeque с использованием STL - контейнера vector
(например из двух векторов сделать одну очередь, так, что вставка в начало очереди – это
вставка в конец первого вектора, а вставка в конец очереди – вставка в конец второго
вектора).Определить в нем свои функции вставки в начало и в конец.
Инстанцировать для своего класса, представляющего строку, изготовленную из vector<char>.
*/

#include <iostream>
#include "mydeque.h"

int main()
{
    Mydeque<char> dq(1);
    dq.push_front('A');
    dq.push_front("ABCD", 4);
    dq.push_back('B');
    std::cout << dq.size() << std::endl;
    std::cout << dq << std::endl;
}
