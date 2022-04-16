#include "points.h"

My_point Points::operator [] (int index) {
	return My_point(v[index * 2], v[index * 2 + 1]);
}

const My_point Points::operator [] (const int index) const {
	return My_point(v[index * 2], v[index * 2 + 1]);
}

void Points::set(int index, const My_point& tmp) {
	v[index * 2] = tmp.getx();
	v[index * 2 + 1] = tmp.gety();
}

void Points::add(int vx, int vy) {
	vector::add(vx);
	vector::add(vy);
}

ostream& operator<< (std::ostream& out, const Points& r) {
	out << "Данные массива" << endl;
	out << "x" << "\t" << "y" << endl;
	for(int i = 0; i < r.size(); i++)
	out <<  r[i].getx() << "\t" << r[i].gety() << endl;
	return out;
}