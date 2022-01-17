#include "My_Vector.h"

using namespace std;

My_Vector::My_Vector(int N = 0) : v(0), len(0) {	//�����������	
	if (N > 0)
	v = new double[N];
	if (v) len = N;
};

My_Vector::My_Vector(const My_Vector& temp) : v(0), len(0) {//����������� ����������� ������������, ��������� ������ (���� vector)
													//�� ��� ���������� ������� ���� �� ������
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
		//������� ����� ������ �� 1 ������
		nlen = len + 1;
		nv = new double[nlen];
		//���������, ��� �� ��������
		if (nv){
			//�������� ������ �� ������� ������� � �����
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
		//������� ����� ������ �� �������� �������� ������
		nlen = len - (j - i - 1);
		nv = new double[nlen];
		//���������, ��� �� ��������
		if (nv){
			//�������� ������ �� ������� ������� 
			for (ic = 0; ic < len; ic++){
				if ((ic > i) && (ic < j))	//���� ������ ������ � ���������� ����� i � j
					continue;				//�� ��������
				nv[it] = v[ic];
				it++;
			}

			delete[] v;		//������� ������ ������
			v = nv;			//�������� � ���������� ����� ������ �������
			len = nlen;		//������������� ������ ������ �������
		}
	}
}