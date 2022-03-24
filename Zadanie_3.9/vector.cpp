#include "vector.h"

using namespace std;

vector::vector(int length) : len(0), v(nullptr) {	//Конструктор	
	assert(length >= 0);
	if (length > 0)
		v = new int[length];
	if (v) 
		len = length;
};


vector::vector(const vector& temp) : v(0), len(0) {//Конструктор копирования –конструктор, создающий объект (типа vector)
													//по уже имеющемуся объекту того же класса
	if (temp.len > 0)
		v = new int[temp.len];
	if (v) {
		len = temp.len;
		for (int i = 0; i < len; ++i)
		{
			v[i] = temp.v[i];
		}
	}
};

int vector::size() const { return len; }

int& vector::operator [] (int index)
{
	assert(index >= 0 && index < len);
	return v[index];
}

int vector::operator [] (int index) const
{
	assert(index >= 0 && index < len);
	return v[index];
}

vector::~vector() {
	delete[] v;
}

void vector::insert(int index, int value){
	// Проверка корректности передаваемого индекса
	assert(index >= 0 && index <= len);
	//создаем новый массив на 1 больше
	int* nv = new int[len + 1];
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

void vector::erase(int index){
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
	int* nv = new int[len - 1];
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

void vector::reverce() {
	//создаем временный массив
	int* nv = new int[len];
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