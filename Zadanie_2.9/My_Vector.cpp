#include "My_Vector.h"

using namespace std;

My_Vector::My_Vector(int length) {	//Конструктор	
	assert(length >= 0);
	if (length > 0)
		v = new double[length];
	if (v) 
		len = length;
};


My_Vector::My_Vector(const My_Vector& temp) : v(0), len(0) {//Конструктор копирования –конструктор, создающий объект (типа vector)
													//по уже имеющемуся объекту того же класса
	if (temp.len > 0)
		v = new double[temp.len];
	if (v) {
		len = temp.len;
		for (int i = 0; i < len; ++i)
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

void My_Vector::insert(int index, double value){
	// Проверка корректности передаваемого индекса
	assert(index >= 0 && index <= len);
	//создаем новый массив на 1 больше
	double* nv = new double[len + 1];
	//проверяем, что он создался
	if (nv){
		// Копируем все элементы аж до index-а 
		for (int before = 0; before < index; ++before) 
			nv[before] = v[before];
		//вставляем значение после числа указанного в индексе   
		nv[index] = value;
		// Копируем все значения после вставляемого элемента
		for (int after = index; after < len; ++after) 
			nv[after + 1] = v[after];
		// Удаляем старый массив и используем вместо него новый массив
		delete[] v;
		v = nv;
		++len;
	}
}

void My_Vector::erase(int index){
	// Проверка на корректность передаваемого индекса
	assert(index >= 0 && index < len);
	if (len == 1) {
		delete[] v;
		// Указываем v значение nullptr, чтобы на выходе
		//не было висячего указателя
		v = nullptr;
		len = 0;
		return;
	}
	//создаем новый массив на единицу меньше
	double* nv = new double[len - 1];
	//проверяем, что он создался
	if (nv){
		// Копируем все элементы аж до index-а
		for (int after = 0; after < index; ++after)
			nv[after] = v[after];
		// Копируем все значения после удаляемого элемента
		for (int before = index + 1; before < len; ++before)
			nv[before - 1] = v[before];
		delete[] v;		//удаляем старый массив
		v = nv;			//копируем в переменную адрес нового массива
		--len;		//устанавливаем размер нового массива
	}
}

void My_Vector::reverce() {
	//создаем временный массив
	double* nv = new double[len];
	int i_nv = 0;
	//проверяем, что он создался
	if (nv) {
		for (int i = len; i > 0; --i) { //цикл с последнего элемента массива
			//первому элементу временного массива присваиваем значение последнего
			nv[i_nv] = v[i - 1]; 
			++i_nv;
		}
		delete[] v;		//удаляем старый массив

		v = nv;			//копируем в переменную адрес нового массива
	}
}