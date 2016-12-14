#include <iostream>
#include "day.h"
#include "Util.h"
using namespace std;
#define white (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN)
#define yellow (FOREGROUND_RED | FOREGROUND_GREEN)
#define sky (FOREGROUND_BLUE | FOREGROUND_GREEN)
#define red (FOREGROUND_RED)

Day::Day()
{
	m_day = 0;
	height = 5;
	width = 9;
	m_eCol = Yellow;
}


Day::~Day()
{
}

void Day::DrawRect(int x, int y)
{
	Rect rect(x,y,width,height);
	Display::DrawRect(rect);
	CUtil::Gotoxy(x + 1, y + 1);

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	switch(m_eCol)
	{
		case white:
			SetConsoleTextAttribute(hOut, white | FOREGROUND_INTENSITY);//기본 글자 색상을 흰색으로...
			break;
		case yellow:
			SetConsoleTextAttribute(hOut, yellow | FOREGROUND_INTENSITY);//기본 글자 색상을 흰색으로...
			break;
			SetConsoleTextAttribute(hOut, sky | FOREGROUND_INTENSITY);//기본 글자 색상을 흰색으로...
		case sky:
			break;
		case red:
			SetConsoleTextAttribute(hOut, red | FOREGROUND_INTENSITY);
			break;
	}
	if (m_day > 0)
	{
		cout << m_day;
	}
	SetConsoleTextAttribute(hOut, white | FOREGROUND_INTENSITY);//기본 글자 색상을 흰색으로...
}
void Day::SetDay(int day)
{
	m_day = day;
}

void Day::SetColol(eColor  col)
{
	m_eCol = col;
}
