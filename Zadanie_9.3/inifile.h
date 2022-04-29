#pragma once

#include <fstream>
#include <string>
#include <map>
#include <fstream>
#include <stdexcept>


using namespace std;

class MyIniFile {
private:
	map<string, string> NameValueMap;
	string NameIniFile;
	static ifstream is;
public:
	MyIniFile(string NameFile);
	static bool read(
		std::string& name,          //[out] - имя параметра
		std::string& val)           //[out] - значение параметра
};