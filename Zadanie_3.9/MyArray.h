#pragma once
class MyArrNum
{
protected:
	int* MyNum;
	int length;
public:
	MyArrNum(int num) :MyNum(nullptr), length(0) {}; //конструктор
	MyArrNum(MyArrNum& Arr); // онструктор копировани€
	~MyArrNum(); //деструктор
};

