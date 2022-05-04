
/* 
* Создать класс матриц произвольного (но не изменяемого для непустой матрицы)
* размера, реализовать в нем методы транспонирования матрицы, считывания матрицы
* из файла, записи матрицы в файл.
*/

#include <iostream>
#include "Matrix.h"

using namespace std;

int main()
{
    Matrix <float> m(4, 4);

    m.print();

    cout << "\n";
    // Recently added
    cout << m(1, 1);
    cout << "\n";
    m.transposition();
    m.print();
    
}
