#pragma once

#include <stdlib.h>
#include <cassert>

class My_Vector
{
protected:
	double* v;
	int len;	
public:	
	My_Vector(int N);	//Конструктор	
	My_Vector(const My_Vector& temp);//Конструктор копирования –конструктор, создающий объект (типа vector)
													//по уже имеющемуся объекту того же класса
	int size() const;
	double& operator [] (int index); // для использования в левой части присваивания:
	double operator [] (int index) const; // для использования в правой части присваивания:
	~My_Vector(); //Деструктор
	void insert();
	void erase(int i, int j);
};

