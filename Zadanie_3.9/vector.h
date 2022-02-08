#pragma once

#include <stdlib.h>
#include <cassert>

class vector
{
protected:
	int* v;
	int len;	
public:	
	vector();	//Конструктор	
	vector(int length);
	vector(const vector& temp);//Конструктор копирования –конструктор, создающий объект (типа vector)
													//по уже имеющемуся объекту того же класса
	int size() const;
	int& operator [] (int index); // для использования в левой части присваивания:
	int operator [] (int index) const; // для использования в правой части присваивания:
	~vector(); //Деструктор	
	void insert(int index, int value);
	void erase(int del_num);
	void reverce();
};

