/*
*Построить траекторию движения тела брошенного под углом к горизонту, с учетом
*сопротивления воздуха, пропорционального квадрату скорости тела относительно
*воздуха. Тело начало движение в точке (x0,y0), c начальной скоростью (Vx0,Vy0).
*Траектория должна заканчиваться либо в точке удара тела о землю, либо в точке вылета
*тела за границы экрана.
*/
#include <iostream>
#include <windows.h>
#include "resource.h"
#include "points.h"
#include "point.h"
#include <math.h>

using namespace std;

Points ap_f, ap_p; //массивы в физической и пиксельной системах

int WINAPI DlgProc(HWND hDlg, WORD wMsg, WORD wParam, DWORD)
{
	PAINTSTRUCT ps;	
	if (wMsg == WM_CLOSE || wMsg == WM_COMMAND && wParam == IDOK) {
		EndDialog(hDlg, 0);
	}
	else
		if (wMsg == WM_INITDIALOG) {
			/* Узнаем размер окна (ось OY направлена вниз): */
			RECT rc;
			GetClientRect(hDlg, &rc);
			int dx = rc.right - rc.left;
			int dy = rc.bottom - rc.top;
			My_point mp = { 0.0, (double)dy };
			/* Преобразование массива из физической в пиксельную системы*/
			for (int i = 0; i < ap_f.size(); i++) {
				ap_p.set(i, mp - ap_f[i]);
			}
			//cout << ap_p << endl;		}
		else
			if (wMsg == WM_PAINT) {
				BeginPaint(hDlg, &ps);
				/* Зададим цвет линий: */
				HPEN hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
				HPEN hOldPen = (HPEN)SelectObject(ps.hdc, hPen);
				POINT ptOld;
				MoveToEx(ps.hdc, (int)ap_p[0].getx(), (int)ap_p[0].gety(), &ptOld);
				for (int i = 0; i < ap_f.size(); i++) {
					LineTo(ps.hdc, (int)ap_p[i].getx(), (int)ap_p[i].gety());
				}
				/* Перо нам больше не требуется, уничтожим его: */
				SelectObject(ps.hdc, hOldPen);
				DeleteObject(hPen);
				EndPaint(hDlg, &ps);
			}
	return 0;
}

int main()
{
	setlocale(LC_CTYPE, "rus");
	int	V = 1,		//начальная скорость
		deg = 0;	//угол под которым бросили тело в градусах
	double tm = 0;	//необходимый промежуток времени
	int x, y = 0;	//координаты начала движения тела

	/* Ввод параметров задачи: */

	cout << "Введите через Enter начальные координаты тела х0 и y0:\n" << flush;
	cin >> x >> y;
	cout << "Введите начальную скорость тела V:\n" << flush;
	cin >> V;
	cout << "Тело брошено под углом:\n" << flush;
	cin >> deg;
	cout << "Введите необходимый промежуток времени:\n" << flush;
	cin>> tm;


	const double pi = 3.14;							//число пи
	const double g = 7.8;							//ускорение свободного падения
	
	/* Расчет движения тела */

	double rad = (deg * pi) / 180;					//угол в радианах
	double V0x = V * cos(rad);						//горизонтальная скорость тела
	double V0y = V * sin(rad);						//вертикальная скорость тела
	double h = (pow(V0y, 2)) / (2 * g) + y;		//максимальный подъем тела
	double t = V0y / (g + pow((2 * h / g), 2));		//время необходимое для падения тела на землю
	//double V0yt = V0y - g * tm;					//вертикальная скорость в заданный момент времени
	//double v = sqrt(pow(V0x, 2) + pow(V0y, 2));	//длинна вектора скорости
	double _x = 0, _y = 0, x2;
	double l = (pow(V, 2) * sin(2 * rad)) / (2 * g) + V0x * sqrt((2 * h) / g);

	for (int i = 0; i < tm; i++) {
		_x = (l - x) / 50 * i + x;
		x2 = l / 50 * i + x;
		_y = y + (x2 - x) * tan(rad) - 0.5 * g * pow((x2 - x) / V0x, 2);
		ap_f.add(_x, _y);  //массив в физической системе
		ap_p.add(0, 0);
	}

	/* Вывод на экран массива */
	cout << ap_f << endl;
	DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

