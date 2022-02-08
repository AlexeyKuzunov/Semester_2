#include "vector.h"

using namespace std;

vector::vector(int length) : len(0), v(nullptr) {	//�����������	
	assert(length >= 0);
	if (length > 0)
		v = new int[length];
	if (v) 
		len = length;
};


vector::vector(const vector& temp) : v(0), len(0) {//����������� ����������� ������������, ��������� ������ (���� vector)
													//�� ��� ���������� ������� ���� �� ������
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

vector::~vector() { delete[] v; }

void vector::insert(int index, int value){
	// �������� ������������ ������������� �������
	assert(index >= 0 && index <= len);
	//������� ����� ������ �� 1 ������
	int* nv = new int[len + 1];
	//���������, ��� �� ��������
	if (nv){
		// �������� ��� �������� �� �� index-� 
		for (int before = 0; before < index; ++before) 
			nv[before] = v[before];
		//��������� �������� ����� ����� ���������� � �������   
		nv[index] = value;
		// �������� ��� �������� ����� ������������ ��������
		for (int after = index; after < len; ++after) 
			nv[after + 1] = v[after];
		// ������� ������ ������ � ���������� ������ ���� ����� ������
		delete[] v;
		v = nv;
		++len;
	}
}

void vector::erase(int index){
	// �������� �� ������������ ������������� �������
	assert(index >= 0 && index < len);
	if (len == 1) {
		delete[] v;
		// ��������� v �������� nullptr, ����� �� ������
		//�� ���� �������� ���������
		v = nullptr;
		len = 0;
		return;
	}
	//������� ����� ������ �� ������� ������
	int* nv = new int[len - 1];
	//���������, ��� �� ��������
	if (nv){
		// �������� ��� �������� �� �� index-�
		for (int after = 0; after < index; ++after)
			nv[after] = v[after];
		// �������� ��� �������� ����� ���������� ��������
		for (int before = index + 1; before < len; ++before)
			nv[before - 1] = v[before];
		delete[] v;		//������� ������ ������
		v = nv;			//�������� � ���������� ����� ������ �������
		--len;		//������������� ������ ������ �������
	}
}

void vector::reverce() {
	//������� ��������� ������
	int* nv = new int[len];
	int i_nv = 0;
	//���������, ��� �� ��������
	if (nv) {
		for (int i = len; i > 0; --i) { //���� � ���������� �������� �������
			//������� �������� ���������� ������� ����������� �������� ����������
			nv[i_nv] = v[i - 1]; 
			++i_nv;
		}
		delete[] v;		//������� ������ ������

		v = nv;			//�������� � ���������� ����� ������ �������
	}
}