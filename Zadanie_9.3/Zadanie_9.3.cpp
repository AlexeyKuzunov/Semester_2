/*
Создайте класс, работающий с конфигурационными файлами вида:
Temperature = 273.0
Pressure = 1e+5
N = 100
kB = 1.38e-23
Save result = true
Реализуйте в нем метод открытия файла. Создайте дружественную шаблонную
функцию, которая в качестве аргумента принимает строку – название параметра в
конфигурационном файле, возвращает его значение (которое может быть, целым,
вещественным или булевским типом). Работа с файлом должна осуществляться с
помощью функций библиотеки <fstream>.
*/

#include <iostream>
#include "inifile.h"
#include <string>

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "rus");
    string str;
    cout << "Введите имя файла параметров (param.ini) " << flush;
    getline(cin, str);
    MyIniFile MyFile(str.c_str());
    MyFile.PrintMap();
    str.clear();
    double d = ViewVal<double>(MyFile, "Pressure");
    cout << d << endl;
    bool b = ViewVal(MyFile, "Save result");
    cout << std::boolalpha << b << endl;
}


