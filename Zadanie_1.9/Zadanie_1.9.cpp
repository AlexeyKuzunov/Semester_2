﻿/*
* Создать класс прямоугольников, со сторонами, параллельными осям координат.
* Определить в нем конструктор, деструктор, конструктор копирования. Перегрузить операции «+», «-»,
* «+=», «-=», «*», «/», «=» (умножение и деление – на вещественное число). Перегрузить операции ввода и
* вывода. Написать программу – калькулятор, который позволит пользователю производить арифметические
* операции с объектами данного класса
*/

#include <iostream>
#include "Rectangle.h"

int main()
{
    setlocale(LC_CTYPE, "rus");
    MyRectangle first, second, total;
    std::cin >> first;
    std::cin >> second;
    total = first - second;
    std::cout << total << "\n";
}
