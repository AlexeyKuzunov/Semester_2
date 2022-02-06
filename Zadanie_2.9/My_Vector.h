#pragma once

#include <stdlib.h>
#include <cassert>

class My_Vector
{
protected:
	double* v;
	int len;	
public:	
	My_Vector() : len(0), v(nullptr) {}	//�����������	
	My_Vector(int length);
	My_Vector(const My_Vector& temp);//����������� ����������� ������������, ��������� ������ (���� vector)
													//�� ��� ���������� ������� ���� �� ������
	int size() const;
	double& operator [] (int index); // ��� ������������� � ����� ����� ������������:
	double operator [] (int index) const; // ��� ������������� � ������ ����� ������������:
	~My_Vector(); //����������
	void insert(double value, int index);
	void erase(int i, int j);
	void reverce();
};

