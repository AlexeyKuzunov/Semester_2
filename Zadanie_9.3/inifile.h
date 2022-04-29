#pragma once

#include <fstream>
#include <string>
#include <map>
#include <fstream>
#include <stdexcept>

/*
1. открыть файл
2. загрузить его содержимое в map <string, string>
3. Функция возвращает целое, вещественное или bool. Как определить что в string?
*/

using namespace std;

class MyIniFile {
private:
	map<string, string> NameValueMap;
	string NameIniFile;
	static ifstream is;
public:
	MyIniFile(string NameFile);
	static bool read(
		std::string& name,          //[out] - èìÿ ïàðàìåòðà
		std::string& val)           //[out] - çíà÷åíèå ïàðàìåòðà
};
