/*Построить траекторию падения тела в поле силы тяжести, если тело начало движение в
точке(x0, y0), c начальной скоростью(Vx0, Vy0).Начальные условия задает пользователь.
Удар о землю абсолютно неупругий.Следовательно, траектория должна заканчиваться
либо в точке удара тела о землю, либо в точке вылета тела за границы экрана
*/

#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <time.h>

using namespace std;

double alpha(double _V, double _alf, double _timer) {
    double cos_timer = cos(_timer);
    //cout << "time"
    //cout << (_alpha_0 * cos((_w2 - _w1) * _timer / 2) * cos((_w2 + _w1) * _timer / 2)) << endl;
    return ((_V * sin(_alf) * _timer) - (9, 81 * _timer * _timer) / 2);
}

int main()
{
    setlocale(LC_CTYPE, "rus");

    double alf = 60;
    double V_0 = 10;
    double timer = 0;
    float x;

    HDC hDC = GetDC(GetConsoleWindow()); //переменная, связанная с окном
    HPEN Pen = CreatePen(PS_DOT, 2, RGB(250, 255, 255)); //виртуальная ручка, рисующая на консоли

    //объект
    SelectObject(hDC, Pen); //создание объекта
    MoveToEx(hDC, 0, 400, NULL); //движение по х (ВСЕ НИЖЕ В ПИКСЕЛЯХ)
    LineTo(hDC, 800, 400); // ось x и ее начало координат

    MoveToEx(hDC, 20, 0, NULL); //движение по y (это из Windows, прога понимает)
    LineTo(hDC, 20, 400); // ось y и ее начало координат

    TCHAR a[45]; //обозначение для вывода текста,  45 - оставление  памяти??

    for (timer = 0; timer <= 7; timer += 1) // ось х - время, начинается с 0 и до 7, с шагом 1
    {
        Rectangle(hDC, timer * 100 + 19, 395, timer * 100 + 21, 405); //риски на оси
        int g = timer; //переменная, для названия рисок
        SetBkMode(hDC, TRANSPARENT); //за надписью нет цвета
        SetTextColor(hDC, RGB(255, 255, 255)); //цвет текста
        swprintf_s(a, 45, L"%d", g); // вывод подписей на рисках
        TextOut(hDC, timer * 100 + 16, 405, a, 1); //рассчет пикселей, на каком расстоянии они находятся друг от друга

    }

    for (double y = 0; y >= -8; y -= 1) // для оси у, все то же самое!!! но там есть перерассчет
    {
        //Rectangle(hDC, 15, y*50+249, 25, y*50+251); //риски на оси
        Rectangle(hDC, 15, y * 50 + 199, 25, y * 50 + 201);
        float g = -y;

        SetBkMode(hDC, TRANSPARENT);
        SetTextColor(hDC, RGB(255, 255, 255));

        //swprintf_s(a, 45, L"-%.1f", g);
       // TextOut(hDC, 0, y * 50 + 194, a, 4);

        swprintf_s(a, 45, L"%.1f", g);
        TextOut(hDC, 0, y * 50 + 394, a, 4);

    }
    //подписи к оси х и у
    SetBkMode(hDC, TRANSPARENT);
    SetTextColor(hDC, RGB(255, 255, 255));

    swprintf_s(a, 20, L"time, t");
    TextOut(hDC, 750, 200, a, 7);

    swprintf_s(a, 20, L"S, m");
    TextOut(hDC, 30, 25, a, 8);

    //переопределение цвета для графика

    Pen = CreatePen(PS_DOT, 2, RGB(0, 206, 205));
    SelectObject(hDC, Pen);

    //вывод графика
    for (timer = 0; timer <= 7; timer += 0.001) // O(100,85) - center
    {

        MoveToEx(hDC, 100 * timer + 20, 100 * alpha(V_0, alf, timer) + 400, NULL);//10 - scale
        LineTo(hDC, 100 * timer + 20, 100 * alpha(V_0, alf, timer) + 400);
    }


    // Это не трогать, без этого не работает!

    int timer_for_console = time(NULL) + 50;
    //cout << "Консоль очистится через " << timer - time(NULL) << " ";

    while (timer_for_console > time(NULL))
    {
        //cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
        //cout << "Консоль очистится через " << timer - time(NULL) << " секунд";
    }
    return 0;
}