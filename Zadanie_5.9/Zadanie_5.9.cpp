﻿/*
*Построить траекторию движения тела брошенного под углом к горизонту, с учетом
*сопротивления воздуха, пропорционального квадрату скорости тела относительно
*воздуха. Тело начало движение в точке (x0,y0), c начальной скоростью (Vx0,Vy0).
*Траектория должна заканчиваться либо в точке удара тела о землю, либо в точке вылета
*тела за границы экрана.
*/
#include <iostream>
#include <windows.h>
#include "resource.h"

using namespace std;

/* Блок глобальных переменных (массивы заранее рассчитанных координат)
в двух системах: физической (вещественные координаты) и пиксельной,
связанной с текущим окном, в котором производится отрисовка траектории.
*/
int x1, y1_, x2, y2;

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
				MoveToEx(ps.hdc, x1, y1_, &ptOld);
				LineTo(ps.hdc, x2, y2);
				/* Перо нам больше не требуется, уничтожим его: */
				SelectObject(ps.hdc, hOldPen);
				DeleteObject(hPen);
				EndPaint(hDlg, &ps);
			}
	return 0;
}

int main()
{
	/* Ввод параметров задачи: */
	cout << "Please, enter 4 coords:\n" << flush;
	cin >> x1 >> y1_ >> x2 >> y2;
	cout << "x1 = " << x1 << "\ny1 = " << y1_
		<< "\nx2 = " << x2 << "\ny2 = " << y2 << "\n" << flush;
	/*
	Здесь, перед показом, нужно расчитать координаты
	всех точек траектории в физической системе координат.
	Массивы x-y координат должны быть доступны глобально -
	в DlgProc и в функции main.
	*/
	DialogBox(NULL, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

