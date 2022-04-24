/*��������� ���������� ������� ���� � ���� ���� �������, ���� ���� ������ �������� �
�����(x0, y0), c ��������� ���������(Vx0, Vy0).��������� ������� ������ ������������.
���� � ����� ��������� ���������.�������������, ���������� ������ �������������
���� � ����� ����� ���� � �����, ���� � ����� ������ ���� �� ������� ������
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

    HDC hDC = GetDC(GetConsoleWindow()); //����������, ��������� � �����
    HPEN Pen = CreatePen(PS_DOT, 2, RGB(250, 255, 255)); //����������� �����, �������� �� �������

    //������
    SelectObject(hDC, Pen); //�������� �������
    MoveToEx(hDC, 0, 400, NULL); //�������� �� � (��� ���� � ��������)
    LineTo(hDC, 800, 400); // ��� x � �� ������ ���������

    MoveToEx(hDC, 20, 0, NULL); //�������� �� y (��� �� Windows, ����� ��������)
    LineTo(hDC, 20, 400); // ��� y � �� ������ ���������

    TCHAR a[45]; //����������� ��� ������ ������,  45 - ����������  ������??

    for (timer = 0; timer <= 7; timer += 1) // ��� � - �����, ���������� � 0 � �� 7, � ����� 1
    {
        Rectangle(hDC, timer * 100 + 19, 395, timer * 100 + 21, 405); //����� �� ���
        int g = timer; //����������, ��� �������� �����
        SetBkMode(hDC, TRANSPARENT); //�� �������� ��� �����
        SetTextColor(hDC, RGB(255, 255, 255)); //���� ������
        swprintf_s(a, 45, L"%d", g); // ����� �������� �� ������
        TextOut(hDC, timer * 100 + 16, 405, a, 1); //������� ��������, �� ����� ���������� ��� ��������� ���� �� �����

    }

    for (double y = 0; y >= -8; y -= 1) // ��� ��� �, ��� �� �� �����!!! �� ��� ���� �����������
    {
        //Rectangle(hDC, 15, y*50+249, 25, y*50+251); //����� �� ���
        Rectangle(hDC, 15, y * 50 + 199, 25, y * 50 + 201);
        float g = -y;

        SetBkMode(hDC, TRANSPARENT);
        SetTextColor(hDC, RGB(255, 255, 255));

        //swprintf_s(a, 45, L"-%.1f", g);
       // TextOut(hDC, 0, y * 50 + 194, a, 4);

        swprintf_s(a, 45, L"%.1f", g);
        TextOut(hDC, 0, y * 50 + 394, a, 4);

    }
    //������� � ��� � � �
    SetBkMode(hDC, TRANSPARENT);
    SetTextColor(hDC, RGB(255, 255, 255));

    swprintf_s(a, 20, L"time, t");
    TextOut(hDC, 750, 200, a, 7);

    swprintf_s(a, 20, L"S, m");
    TextOut(hDC, 30, 25, a, 8);

    //��������������� ����� ��� �������

    Pen = CreatePen(PS_DOT, 2, RGB(0, 206, 205));
    SelectObject(hDC, Pen);

    //����� �������
    for (timer = 0; timer <= 7; timer += 0.001) // O(100,85) - center
    {

        MoveToEx(hDC, 100 * timer + 20, 100 * alpha(V_0, alf, timer) + 400, NULL);//10 - scale
        LineTo(hDC, 100 * timer + 20, 100 * alpha(V_0, alf, timer) + 400);
    }


    // ��� �� �������, ��� ����� �� ��������!

    int timer_for_console = time(NULL) + 50;
    //cout << "������� ��������� ����� " << timer - time(NULL) << " ";

    while (timer_for_console > time(NULL))
    {
        //cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
        //cout << "������� ��������� ����� " << timer - time(NULL) << " ������";
    }
    return 0;
}