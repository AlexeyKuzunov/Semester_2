#pragma once


#include <iostream>


using namespace std;

//����������� ����������� ����
bool is_leap_year(const int year);
//���������� ���� � ������
short month_day(const int year, const short month);

class Data {
private:
    int Day;
    int Month;
    int Year;
public:
    Data() {
        cout << "������� ����� Enter ����, ����� � ��� \n" << flush;
        cin >> Day >> Month >> Year;
        try {
            if (Year <= 0) throw "��� �� ����� ����������� ��� ������������� ������";
            if (Month <= 0) throw "����� �� ����� ���� ������� ��� �������������";
            if (Month > 12) throw "� ���� ���������� �������";
            if (Day > month_day(Year, Month)) throw "� ������ ������ ������ ����";
        }
        catch (const char* exception) {// ���������� ���������� ���� const char*
            std::cerr << "������: " << exception << '\n';
        }
    }

};


bool is_leap_year(const int year) {
    //���, ����� �������� ������ 400, � ����������
    if ((year % 400) == 0) return true;
    //��������� ����, ����� ������� ������ 100, � ������������
    if ((year % 100) == 0) return false;
    //��������� ����, ����� ������� ������ 4, � ����������
    if ((year % 4) == 0) return true;
    //��������� ���� � ������������
    return false;
}


short month_day(const int year, const short month) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    else {
        if (is_leap_year(year)) return 29;
        else return 28;
    }
}