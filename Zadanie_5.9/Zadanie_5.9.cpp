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
#include <math.h>

using namespace std;

Points ap_f, ap_p; //массивы в физической и пиксельной системах
//int x = 0, y = 0;

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
			/* После этого нужно отмасштабировать физические координаты траектории,
			чтобы они помещались в поле зрения окна. То есть, нужно рассчитать
			для каждой точки траектории пиксельные координаты в системе координат
			данного окна. Само окно пользователь еще не видит.
			*/
			for (int i = 0; i < ap_f.size(); i++) {

			}
		}
		else
			if (wMsg == WM_PAINT) {
				BeginPaint(hDlg, &ps);
				/* Зададим цвет линий: */
				HPEN hPen = (HPEN)CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
				HPEN hOldPen = (HPEN)SelectObject(ps.hdc, hPen);
				/*
				Вот что вообще можно здесь рисовать:
				MoveToEx(ps.hdc,int x,int y,NULL);
				( последний параметр – адрес структуры POINT
				для возврата координат предыдущей позиции )
				LineTo(ps.hdc,int x,int y); (с первого пиксела, но без последнего)
				TextOut(ps.hdc,int x,int y,char* szText,lstrlen(szText));
				Rectangle(ps.hdc,int left,int top,int right,int bottom);
				Ellipse(ps.hdc,int left,int top,int right,int bottom);
				Polygon(ps.hdc,const POINT * lp,int nPoints);
				Polyline(ps.hdc,const POINT * lp,int nPoints);
				SetPixel(ps.hdc,int x,int y, RGB(red,green,blue));
				*/
				/* Здесь – производится отрисовка расчитанных пиксельных координат
				траектории в виде ломаной, в цикле по общему количеству точек.
				*/
				POINT ptOld;
				//MoveToEx(ps.hdc, x, y, &ptOld);
				//LineTo(ps.hdc, _x2, _y2);

				/* Преобразование массива из физической в пиксельную системы*/


				/* Перо нам больше не требуется, уничтожим его: */
				SelectObject(ps.hdc, hOldPen);
				DeleteObject(hPen);
				EndPaint(hDlg, &ps);
			}
	return 0;
}

int main()
{
	//int dx = 50;
	int x0, y0=0,								//координаты начала движения тела
		V = 1,									//начальная скорость
		deg = 0;								//угол под которым бросили тело в градусах
	double tm = 0;								//необходимый промежуток времени

	/* Ввод параметров задачи: */

	cout << "Please, enter 5 coords:\n" << flush;
	cin >> x0 >> y0 >> V >> deg >> tm;

	const double pi = 3.14;							//число пи
	const double g = 7.8;							//ускорение свободного падения
	
	/* Расчет движения тела */

	double rad = (deg * pi) / 180;					//угол в радианах
	double V0x = V * cos(rad);						//горизонтальная скорость тела
	double V0y = V * sin(rad);						//вертикальная скорость тела
	double h = (pow(V0y, 2)) / (2 * g) + y0;		//максимальный подъем тела
	double t = V0y / (g + pow((2 * h / g), 2));		//время необходимое для падения тела на землю
	//double V0yt = V0y - g * tm;					//вертикальная скорость в заданный момент времени
	//double v = sqrt(pow(V0x, 2) + pow(V0y, 2));	//длинна вектора скорости
	double _x = 0, _y = 0, x2;
	double l = (pow(V, 2) * sin(2 * rad)) / (2 * g) + V0x * sqrt((2 * h) / g);

	for (int i = 0; i < tm; i++) {
		_x = (l - x0) / 50 * i + x0;
		x2 = l / 50 * i + x0;
		_y = y0 + (x2 - x0) * tan(rad) - 0.5 * g * pow((x2 - x0) / V0x, 2);
		ap_f.add(_x, _y);  //массив в физической системе

	}

	/* Вывод на экран массива */
	cout << ap_f << endl;


	/* Ввод параметров задачи: */
	//cout << "Please, enter 4 coords:\n" << flush;
	//cin >> x >> y >> _x2 >> _y2;
	//cout << "x1 = " << x << "\n y1 = " << y
	//	<< "\n x2 = " << _x2 << "\n y2 = " << _y2 << "\n" << flush;
	/*
	Здесь, перед показом, нужно расчитать координаты
	всех точек траектории в физической системе координат.
	Массивы x-y координат должны быть доступны глобально -
	в DlgProc и в функции main.
	*/
	// DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

