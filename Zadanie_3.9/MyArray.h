#pragma once
class MyArrNum
{
	int* MyNum;
	int length;

public:
	MyArrNum(int num); //�����������
	MyArrNum(MyArrNum& Arr); //����������� �����������
	~MyArrNum(); //����������
};

