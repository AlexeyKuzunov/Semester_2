#pragma once

#include <iostream>

template <class T>
class Matrix {
private:
    T** data;
    int row, col;
public:
    Matrix(int rows, int cols)
    {
        setRow(rows);
        setCol(cols);

        data = new T * [rows];

        for (int i = 0; i < row; i++) {
            data[i] = new T[cols];
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = (T)i * j;
            }
        }
    }

    void print();
    void setRow(int r) { row = r; }
    void setCol(int c) { col = c; }
    T& operator()(int row, int col);
    void transposition();


};

template <class T>
void Matrix<T>::print()
{
    int i, j;

    for (i = 0; i < row; i++) { // Here you used to have row hard coded to 4    
        for (j = 0; j < col; j++) { // Here you used to have col hard coded to 4        
            std::cout << (float)data[i][j];
        }
        std::cout << "\n";
    }
}


template<class T> T& Matrix<T>::operator()(int row, int col)
{
    return data[row][col];
}

template<class T>
inline void Matrix<T>::transposition()
{
   
}


