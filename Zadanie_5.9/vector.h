#pragma once

#include <stdlib.h>
#include <cassert>

class vector
{
protected:
	double* v;
	int len;	
public:	
	vector() : len(0), v(nullptr) {};	//Конструктор	
	vector(int length);
	vector(const vector& temp);//Конструктор копирования –конструктор, создающий объект (типа vector)
													//по уже имеющемуся объекту того же класса
	int size() const;
	double& operator [] (int index); // для использования в левой части присваивания:
	double operator [] (int index) const; // для использования в правой части присваивания:
	~vector(); //Деструктор	
	void insert(int index, double value);
	void erase(int del_num);
	void add(double value);
	void reverce();
};