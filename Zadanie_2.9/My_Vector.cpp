#include "My_Vector.h"

using namespace std;

My_Vector::My_Vector(int length) {	// онструктор	
	assert(length >= 0);
	if (length > 0)
	v = new double[length];
	if (v) len = length;
};


My_Vector::My_Vector(const My_Vector& temp) : v(0), len(0) {// онструктор копировани€ Цконструктор, создающий объект (типа vector)
													//по уже имеющемус€ объекту того же класса
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

void My_Vector::insert(double value, int index){
	// ѕроверка корректности передаваемого индекса
	assert(index >= 0 && index <= len);
	//создаем новый массив на 1 больше
	double* nv = new double[len + 1];
	//провер€ем, что он создалс€
	if (nv){
		//копируем данные из старого массива в новый
		for (int i = 0; i < index; i++)
			nv[i] = v[i];
		nv[index] = value;
		delete[] v;
		v = nv;
		++len;
	}
}

void My_Vector::erase(int i, int j){
	double* nv;
	int ic, nlen, it = 0;
	if ((len > 0) || ((j - i) > 1)){
		//создаем новый массив на разность индексов меньше
		nlen = len - (j - i - 1);
		nv = new double[nlen];
		//провер€ем, что он создалс€
		if (nv){
			//копируем данные из старого массива 
			for (ic = 0; ic < len; ic++){
				if ((ic > i) && (ic < j))	//если индекс входит в промежуток между i и j
					continue;				//не копируем
				nv[it] = v[ic];
				it++;
			}

			delete[] v;		//удал€ем старый массив
			v = nv;			//копируем в переменную адрес нового массива
			len = nlen;		//устанавливаем размер нового массива
		}
	}
}