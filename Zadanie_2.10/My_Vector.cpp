#include "My_Vector.h"

using namespace std;

My_Vector::My_Vector(int N = 0) : v(0), len(0) {	//Конструктор	
	if (N > 0)
	v = new double[N];
	if (v) len = N;
};

My_Vector::My_Vector(const My_Vector& temp) : v(0), len(0) {//Конструктор копирования –конструктор, создающий объект (типа vector)
													//по уже имеющемуся объекту того же класса
	if (temp.len > 0)
		v = new double[temp.len];
	if (v) {
		len = temp.len;
		for (int i = 0; i < len; i++)
		{
			v[i] = temp.v[i];
		}
	}
};

int My_Vector::size() const { return len; }

double& My_Vector::operator [] (int index)
{
	assert(index >= 0 && index < len);
	return v[index];
}

double My_Vector::operator [] (int index) const
{
	assert(index >= 0 && index < len);
	return v[index];
}

My_Vector::~My_Vector() { delete[] v; }

void My_Vector::insert(){
	double* nv;
	int i, nlen;

	if (len > 0) {
		//создаем новый массив на 1 больше
		nlen = len + 1;
		nv = new double[nlen];
		//проверяем, что он создался
		if (nv){
			//копируем данные из старого массива в новый
			for (i = 0; i < len; i++){
				nv[i] = v[i];
			}
			delete[] v;
			v = nv;
			len = nlen;
		}
	}
}

void My_Vector::erase(int i, int j){
	double* nv;
	int ic, nlen, it = 0;
	if ((len > 0) || ((j - i) > 1)){
		//создаем новый массив на разность индексов меньше
		nlen = len - (j - i - 1);
		nv = new double[nlen];
		//проверяем, что он создался
		if (nv){
			//копируем данные из старого массива 
			for (ic = 0; ic < len; ic++){
				if ((ic > i) && (ic < j))	//если индекс входит в промежуток между i и j
					continue;				//не копируем
				nv[it] = v[ic];
				it++;
			}

			delete[] v;		//удаляем старый массив
			v = nv;			//копируем в переменную адрес нового массива
			len = nlen;		//устанавливаем размер нового массива
		}
	}
}