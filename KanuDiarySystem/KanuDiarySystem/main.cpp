#include <iostream>

#include "Util.h"

int main()
{

	/*Display::DrawXLine(Point(0,0),100);
	Display::DrawYLine(Point(0,0),100);*/
	CUtil::setcursortype(CURSOR_TYPE::NOCURSOR);
	Display::DrawRect(Point(10,10),Point(50,4));

	getchar();
	return 0;
}