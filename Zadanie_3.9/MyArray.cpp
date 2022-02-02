#include "MyArray.h"

MyArrNum::MyArrNum(int num) {
	if (MyNum > 0) MyNum = new int[num];
	if (length) length = num;
}

MyArrNum::MyArrNum(MyArrNum& Arr) {
	if (Arr.length > 0) MyNum = new int[Arr.length];
	if(MyNum){
		length = Arr.length;
		*MyNum = *Arr.MyNum;
	}
}

MyArrNum::~MyArrNum() {
	if(MyNum) delete[] MyNum;
}