﻿/******************************************************************************
Создать класс полиномов 4 порядка. Определить в нем конструктор, деструктор, конструктор
копирования. Перегрузить операции «+»,«-»,«+=»,«-=»,«*»,«/»,«=»(умножение и деление –на
вещественное число).Перегрузить операции ввода и вывода. Написать программу –калькулятор,
который позволит пользователю производить арифметические операции (+,-) с объектами данного класса.

******************************************************************************/

#include <iostream>
#include "Polinom_4.h"

void main()
{
    char op;
    Polinom A, B, C;
    setlocale(LC_CTYPE, "rus");
    std::cout << "Калькулятор для полиномов 4-й степени: \n" << endl << flush;
    std::cout << "Введите коэффициенты 1-го полинома: \n" << endl << flush;
    std::cin >> A;
    std::cout << A << '\n';
    std::cout << "Введите коэффициенты 2-го полинома: \n" << endl << flush;
    std::cin >> B;
    std::cout << B << '\n';
    cout << "Введите оператор: " << endl << flush;
    cin >> op;
    cout << "Решение: \n";

    switch (op)
    {
    case'+': C = A + B; break;
    case'-': C = A - B; break;
    default:cerr << "Error!" << flush;
        return;
    }

    cout << A << '\n' << op << '\n' << B << '\n' << "=" << '\n' << C << '\n' << flush;
    system("pause");
}