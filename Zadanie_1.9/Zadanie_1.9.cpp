/*
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
    char op;
    MyRectangle first;
    std::cout << "Введите операцию: ";
    std::cin >> op;
    std::cin >> first;
    switch (op) {
    case '-': {
        MyRectangle second;
        std::cin >> second;
        first = first - second;
        std::cout << first;
        break;
        }
    case '+': {
        MyRectangle second;
        std::cin >> second;
        first += second;
        std::cout << first;
        break;
    }
    case '*': {
        double num;        
        std::cout << "Введите число: ";
        std::cin >> num;
        first = first * num;
        std::cout << first;
        break;
    }
    case '/': {
        double num;
        std::cout << "Введите число: ";
        std::cin >> num;
        first = first / num;
        std::cout << first;
        break;
    }
    default:cerr << "Error!" << flush;
    }
}
