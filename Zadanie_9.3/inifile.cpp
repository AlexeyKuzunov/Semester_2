
#include "inifile.h"


using namespace std;

MyIniFile::MyIniFile(string NameFile) {
    string name, val;
    char ch;
    is.open(NameFile.c_str());
    if (!is) throw "Файл не существует";
    while (is) {
        name.erase();
        while (is.get(ch) && (ch != '='))
            name.push_back(ch);

        if (name[name.length() - 1] == ' ')
            name.erase(name.length() - 1, 1);
    
        val.erase();
        while (is.get(ch) && (ch != '\n'))
            val.push_back(ch);

        if (val.length() > 0 && val[0] == ' ')
            val.erase(0, 1);
        ValueMap[name] = val;
    }
    
}

void MyIniFile::PrintMap() {
    for (auto it = ValueMap.begin(); it != ValueMap.end(); ++it)
    {
        cout << it->first << " : " << it->second << endl;
    }
}