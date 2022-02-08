#pragma once

#include <stdlib.h>
#include <cassert>

class vector
{
protected:
	int* v;
	int len;	
public:	
	vector();	//�����������	
	vector(int length);
	vector(const vector& temp);//����������� ����������� ������������, ��������� ������ (���� vector)
													//�� ��� ���������� ������� ���� �� ������
	int size() const;
	int& operator [] (int index); // ��� ������������� � ����� ����� ������������:
	int operator [] (int index) const; // ��� ������������� � ������ ����� ������������:
	~vector(); //����������	
	void insert(int index, int value);
	void erase(int del_num);
	void reverce();
};

