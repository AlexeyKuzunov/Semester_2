#pragma once

#include <fstream>
#include <string>
#include <map>
#include <fstream>
#include <stdexcept>
#include <iostream>

/*
1. открыть файл
2. загрузить его содержимое в map <string, string>
3. Функция возвращает целое, вещественное или bool. Как определить что в string?
*/

using namespace std;

class MyIniFile {
private:
	map<string, string> ValueMap;
	ifstream is;
public:
	MyIniFile(string NameFile);
	~MyIniFile() { is.close();}
	void PrintMap();

};
