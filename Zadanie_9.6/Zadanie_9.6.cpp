
/* 
* Создать класс матриц произвольного (но не изменяемого для непустой матрицы)
* размера, реализовать в нем методы транспонирования матрицы, считывания матрицы
* из файла, записи матрицы в файл.
*/

#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    //Создаем новую матрицу
    Matrix <int> m(5, 6);
    //Заполняем тестовыми данными
    m.fillTestArray();
    //выводим на экран
    m.print();
    //сохраняем матрицу ы файл
    m.SaveToFile("matrix.txt");
    cout << "\n";
    //транспонируем
    m.transposition();
    cout << "\n";
    //выводим на экран результат
    m.print();
    //загружаем ранее сохраненную первоначальную иатрицу
    m.LoadFile("matrix.txt");
    cout << "\n";
    //выводим на экран первоначальную матрицу
    m.print();
    
}
