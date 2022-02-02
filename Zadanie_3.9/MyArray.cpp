#include "MyArray.h"

MyArrNum::MyArrNum(int num) {
	MyNum = new int[num];
	length = num;
}

MyArrNum::MyArrNum(MyArrNum& Arr) {

}

MyArrNum::~MyArrNum() {
	delete[] MyNum;
}