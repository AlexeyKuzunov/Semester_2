#pragma once

#include <iostream>
#include <iomanip>  //для setw
#include <string>
#include <fstream>

using namespace std;

template <class T>
class Matrix {
private:
    T** data;
    int row, col;
public:
    Matrix() { data = nullptr; row = 0; col = 0; } //Конструктор по умолчанию

    Matrix(int rows, int cols) {//конструктор с указанием размера матрицы    
        int tmp = 0;
        setRow(rows);
        setCol(cols);

        data = new T * [row];

        for (int i = 0; i < row; i++) {
            data[i] = new T[col];
        }
    }

    void fillTestArray();
    void print();
    void setRow(int r) { row = r; }
    void setCol(int c) { col = c; }
    T& operator()(int row, int col);
    void transposition();
    int LoadFile(string FileName); //создаем массив на основании его разинра из файла и переносим данные
    int SaveFile(string FileName); //В начале файла сохраняем размер массива, потом перенос строки и данные


};

//Заполнение массива
template <class T>
void Matrix<T>::fillTestArray() {
    T tmp = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            tmp++;
            data[i][j] = tmp;
        }
    }
}

//Вывод массива на экран
template <class T>
void Matrix<T>::print()
{
    int i, j;

    for (i = 0; i < row; i++) { // цикл по строкам    
        for (j = 0; j < col; j++) { // цикл по сначениям строк
            std::cout << std::setw(3); //устанавливаем ширину значений
            std::cout << (T)data[i][j];
        }
        std::cout << "\n";
    }
}


template<class T>
T& Matrix<T>::operator()(int row, int col)
{
    return data[row][col];
}

//транспонирование матрицы
template<class T>
inline void Matrix<T>::transposition()
{
    T** data_tmp;
    int trow = col, tcol = row;
    int i = 0, j = 0;

    if (row != col) {
        //создаем временную матрицу с количеством строк равным количеству колонок старой матрицы
        //и количеством колонок равным количеству строк старой матрицы
        data_tmp = new T * [trow];
        for (int i = 0; i < trow; i++) {
            data_tmp[i] = new T[tcol];
        }

        for (int ti = 0; ti < trow; ti++) {
            for (int tj = 0; tj < tcol; tj++) {
                if (i < row) {
                    if (j < col) {
                        j = ti;
                        i = tj;
                        data_tmp[ti][tj] = data[i][j];                   
                    }
                }           
            }
        }
        data = data_tmp;
        col = tcol;
        row = trow;
    }
    else {
        data_tmp = new T * [row];
        for (int i = 0; i < row; i++) {
            data_tmp[i] = new T[col];
        }
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                data_tmp[i][j] = data[j][i];
            }
        }
        data = data_tmp;
    }
    
}

template<class T>
int Matrix<T>::LoadFile(string FileName) {

    ifstream is(FileName);
    try {
        if (!is) throw "Файл не существует";
    }
    catch (const char* exception) {
        std::cerr << "Ошибка: " << exception << '\n';
    }
    while (is) {

    }

}

template<class T>
int Matrix<T>::SaveFile(string FileName) {
    ofstream outf(FileName);
    // Если мы не можем открыть этот файл для записи данных,
    try {
        // то выводим сообщение об ошибке и выполняем функцию exit()
        if (!outf) throw "Файл не удалось открыть для записи";
    }
    catch (const char* exception) {
        std::cerr << "Ошибка: " << exception << '\n';
    }
    // Записываем в файл следующие две строки
    
    outf << "Row " << row << endl;
    outf << "Col " << col << endl;

    int i, j;

    for (i = 0; i < row; i++) { // цикл по строкам    
        for (j = 0; j < col; j++) { // цикл по сначениям строк
            outf << (T)data[i][j];
        }
        std::cout << "\n";
    }
    // Когда outf выйдет из области видимости, то деструктор класса ofstream 
    // автоматически закроет наш файл
    return 0;
}