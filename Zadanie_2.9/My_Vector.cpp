#include "My_Vector.h"

using namespace std;

My_Vector::My_Vector(int length) {	//�����������	
	assert(length >= 0);
	if (length > 0)
		v = new double[length];
	if (v) 
		len = length;
};


My_Vector::My_Vector(const My_Vector& temp) : v(0), len(0) {//����������� ����������� ������������, ��������� ������ (���� vector)
													//�� ��� ���������� ������� ���� �� ������
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
	// �������� ������������ ������������� �������
	assert(index >= 0 && index <= len);
	//������� ����� ������ �� 1 ������
	double* nv = new double[len + 1];
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

void My_Vector::erase(int index){
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
	double* nv = new double[len - 1];
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

void My_Vector::reverce() {
	//������� ��������� ������
	double* nv = new double[len];
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