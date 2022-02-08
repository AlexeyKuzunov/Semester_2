#pragma once

#include <stdlib.h>
#include <cassert>

class My_Vector
{
protected:
	double* v;
	int len = 0;	
public:	
	My_Vector() : len(0), v(nullptr) {}	//Конструктор	
	My_Vector(int length);
	My_Vector(const My_Vector& temp);//Конструктор копирования –конструктор, создающий объект (типа vector)
													//по уже имеющемуся объекту того же класса
	int size() const;
	double& operator [] (int index); // для использования в левой части присваивания:
	double operator [] (int index) const; // для использования в правой части присваивания:
	~My_Vector(); //Деструктор	
	void insert(int index, double value);
	void erase(int del_num);
	void reverce();
};

