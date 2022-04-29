
#include "inifile.h"

MyIniFile::MyIniFile(string NameFile) {
	string line;
	is.open(NameFile.c_str());
	while (getline(is, line)) { //цикл по строкам в файле
		for (unsigned int c = 0; c < line.length(); c++) { //цикл по строке
			if(line.at(c) == ' ') line.copy()
		}
	}
}

bool MyIniFile::read(std::string& name, std::string& val) {
    char ch;
    //skip_ws(is);
    if (!is)
        return false;

    //read name
    name.erase();
    while (is.get(ch) && (ch != '='))
        name.push_back(ch);

    //read value
    val.erase();
    while (is.get(ch) && (ch != '\n'))
        val.push_back(ch);

    return true;
}