/*
Создать функцию, убирающую из текстового файла все цифры. Функция принимает
имена входного и выходного файлов.
Файл должен считываться по строкам с использованием функций библиотеки <fstream>, строки должны
записываться в контейнер string библиотеки STL.
*/ 

#include <iostream>
#include <fstream>
#include <cstdlib> // для использования функции exit()
#include <string>
#include <Windows.h>

using namespace std;

int NoNumber(char *infile, char *outfile) {
    wstring line; // - хранилище временных строк 
    wifstream in(infile); // - входной файл (нужно создать в папке с програмой in.txt)
    wofstream out(outfile); // - выходной файл (будет создан сам)

    while (getline(in, line)) {
        for (unsigned int c = 0; c < line.length(); c++){
            if (c >= line.length()) // - из-за изменений размера строки
                break;
            if (isdigit(line[c])) {// - если найдена цифра            
                line.erase(line.begin() + c); // - удаление символа
                c--;
            }
        }
        out << line << '\n';
    }
    cout << "Текст обработан и записан в out.txt.\n";
    in.close();
    out.close();
    return 0;
}

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	if (argc == 1) { // если в аргументах только имя программы
		cout << "no arguments!" << endl; // выводим, что нет аргументов
	}
	else 
        return NoNumber(argv[1], argv[2]);

}

