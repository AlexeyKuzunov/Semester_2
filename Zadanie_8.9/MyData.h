#pragma once


#include <iostream>


using namespace std;

//опредерение високосного года
bool is_leap_year(const int year);
//количество дней в мес€це
short month_day(const int year, const short month);

class Data {
private:
    int Day;
    int Month;
    int Year;
public:
    Data() {
        cout << "¬ведите через Enter дату, мес€ц и год \n" << flush;
        cin >> Day >> Month >> Year;
        try {
            if (Year <= 0) throw "год не может бытьнулевым или отрицательным числом";
            if (Month <= 0) throw "мес€ц не может бвть нулевым или отричательным";
            if (Month > 12) throw "в году двенадцать мес€цев";
            if (Day > month_day(Year, Month)) throw "в данном мес€це меньше дней";
        }
        catch (const char* exception) {// обработчик исключений типа const char*
            std::cerr << "ќшибка: " << exception << '\n';
        }
    }

};


bool is_leap_year(const int year) {
    //год, номер которого кратен 400, Ч високосный
    if ((year % 400) == 0) return true;
    //остальные года, номер которых кратен 100, Ч невисокосные
    if ((year % 100) == 0) return false;
    //остальные года, номер которых кратен 4, Ч високосные
    if ((year % 4) == 0) return true;
    //остальные года Ч невисокосные
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