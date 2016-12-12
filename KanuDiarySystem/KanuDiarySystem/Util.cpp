#include "Util.h"


char Display::m_cKey = '*';

CUtil::CUtil(void)
{
}


CUtil::~CUtil(void)
{

}


#include "turboc.h"

// 화면을 모두 지운다.
void CUtil::clrscr()
{
	system("cls");
}

// 커서를 x,y좌표로 이동시킨다.
void CUtil::Gotoxy(Point& pt)
{
	COORD Cur;
	Cur.X= pt.GetX();
	Cur.Y= pt.GetY();
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}

void CUtil::Gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X= x;
	Cur.Y= y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),Cur);
}

Point CUtil::WhereXY()
{
	Point pt;
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&BufInfo);
	pt.SetX(BufInfo.dwCursorPosition.X);
	pt.SetY(BufInfo.dwCursorPosition.Y);
	return pt;
}




//// 커서의 x 좌표를 조사한다.
//int CUtil::wherex()
//{
//	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
//	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&BufInfo);
//	return BufInfo.dwCursorPosition.X;
//}
//
//// 커서의 y좌표를 조사한다.
//int CUtil::wherey()
//{
//	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
//
//	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&BufInfo);
//	return BufInfo.dwCursorPosition.Y;
//}

// 커서를 숨기거나 다시 표시한다.
void CUtil::setcursortype(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c) {
	case CURSOR_TYPE(NOCURSOR):
		CurInfo.dwSize=1;
		CurInfo.bVisible=FALSE;
		break;
	case CURSOR_TYPE(SOLIDCURSOR):
		CurInfo.dwSize=100;
		CurInfo.bVisible=TRUE;
		break;
	case CURSOR_TYPE(NORMALCURSOR):
		CurInfo.dwSize=20;
		CurInfo.bVisible=TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);
}



//가로 라인은 그린다.
void Display::DrawXLine(Point& pt1 , int len)
{
	for(int i = 0 ; i <len ; i++ )
	{		
		CUtil::Gotoxy(pt1.GetX() + i , pt1.GetY());
		printf("%c",Display::m_cKey);
	}
}
//세로 라인을 그린다.
void Display::DrawYLine(Point& pt1 , int len)
{
	for(int i = 0 ; i <len ; i++ )
	{		
		CUtil::Gotoxy(pt1.GetX() , pt1.GetY() + 1);
	}
}

void Display::DrawRect(Point& pt ,Point& size)
{

}


