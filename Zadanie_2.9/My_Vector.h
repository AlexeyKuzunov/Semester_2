#pragma once

#include <stdlib.h>
#include <cassert>

class My_Vector
{
protected:
	double* v;
	int len = 0;	
public:	
	My_Vector() : len(0), v(nullptr) {}	//�����������	
	My_Vector(int length);
	My_Vector(const My_Vector& temp);//����������� ����������� ������������, ��������� ������ (���� vector)
													//�� ��� ���������� ������� ���� �� ������
	int size() const;
	double& operator [] (int index); // ��� ������������� � ����� ����� ������������:
	double operator [] (int index) const; // ��� ������������� � ������ ����� ������������:
	~My_Vector(); //����������	
	void insert(int index, double value);
	void erase(int del_num);
	void reverce();
};

