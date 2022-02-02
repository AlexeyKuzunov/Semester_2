#pragma once
class MyArrNum
{
	int* MyNum;
	int length;

public:
	MyArrNum(int num); //конструктор
	MyArrNum(MyArrNum& Arr); // онструктор копировани€
	~MyArrNum(); //деструктор
};

