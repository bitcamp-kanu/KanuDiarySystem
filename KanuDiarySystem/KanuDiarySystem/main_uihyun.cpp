#include <iostream>

#include "Util.h"
#include"windows.h"
int main()
{
system("mode con:cols=120 lines=100");


	Rect ret(0,0,100,39);
	Rect ret1(0,0,100,3);
	Rect ret2(0,2,70,31);
	Rect ret3(69,2,31,3);
	Rect ret4(69,4,31,15);
	Rect ret5(69,18,31,15);
	Rect ret6(0,32,100,4);
	Rect ret7(0,35,100,4);

	Display::DrawRect(ret);
	Display::DrawRect(ret1);
	Display::DrawRect(ret2);
	Display::DrawRect(ret3);
	Display::DrawRect(ret4);
	Display::DrawRect(ret5);
	Display::DrawRect(ret6);
	Display::DrawRect(ret7);
	Sleep(600);
system("cls");
Rect ret00(0,0,100,39);
Rect ret11(0,0,100,8);
Rect ret22(0,7,100,32);
Rect ret33(0,35,100,4);
	Display::DrawRect(ret00);
	Display::DrawRect(ret11);
	Display::DrawRect(ret22);
	Display::DrawRect(ret33);
		
		Sleep(600);
system("cls");

	Display::DrawRect(ret);
	Display::DrawRect(ret1);
	Display::DrawRect(ret2);
	Display::DrawRect(ret3);
	Display::DrawRect(ret4);
	Display::DrawRect(ret5);
	Display::DrawRect(ret6);
	Display::DrawRect(ret7);


	getchar();
	return 0;
}