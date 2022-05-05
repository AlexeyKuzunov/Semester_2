
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
    Matrix <int> m(5, 5);
    m.fillTestArray();
    m.print();

    cout << "\n";
    m.transposition();
    m.print();

    
}
