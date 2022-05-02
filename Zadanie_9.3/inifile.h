#pragma once

#include <fstream>
#include <string>
#include <map>
#include <stdexcept>
#include <iostream>
#include <sstream>

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
	MyIniFile(const char* NameFile);
	~MyIniFile() { is.close();}
	void PrintMap();
	template <typename T>
	friend const T ViewVal(MyIniFile& myfile, const string name);
	friend const bool ViewVal(MyIniFile& myfile, const string name);
};

template<typename T>
inline const T ViewVal(MyIniFile &myfile, const string name) {
	T tX = 0;
	map <string, string> ::iterator it;
	it = myfile.ValueMap.find(name);
	try {
		if (it == myfile.ValueMap.end()) {
			throw "Параметра с таким ключём не существует";
			exit(1);
		}
		else {
			istringstream(it->second) >> tX;
			return T(tX);
		}
	}
	catch (const char* exception) {// обработчик исключений типа const char*
		std::cerr << "Ошибка: " << exception << '\n';
	}	
}

inline const bool ViewVal(MyIniFile& myfile, const string name) {
	bool tX = 0;
	map <string, string> ::iterator it;
	it = myfile.ValueMap.find(name);
	try {
		if (it == myfile.ValueMap.end()) {
			throw "Параметра с таким ключём не существует";
			exit(1);
		}
		else {
			stringstream myString;
			myString << boolalpha << (it->second);
			myString  >> boolalpha >> tX;
			return tX;
		}
	}
	catch (const char* exception) {// обработчик исключений типа const char*
		std::cerr << "Ошибка: " << exception << '\n';
	}

	
}