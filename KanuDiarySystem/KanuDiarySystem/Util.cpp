#include "Util.h"


char Display::m_cKey = '*';

CUtil::CUtil(void)
{
}


CUtil::~CUtil(void)
{

}


#include "turboc.h"

// ȭ���� ��� �����.
void CUtil::clrscr()
{
	system("cls");
}

// Ŀ���� x,y��ǥ�� �̵���Ų��.
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




//// Ŀ���� x ��ǥ�� �����Ѵ�.
//int CUtil::wherex()
//{
//	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
//	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&BufInfo);
//	return BufInfo.dwCursorPosition.X;
//}
//
//// Ŀ���� y��ǥ�� �����Ѵ�.
//int CUtil::wherey()
//{
//	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
//
//	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&BufInfo);
//	return BufInfo.dwCursorPosition.Y;
//}

// Ŀ���� ����ų� �ٽ� ǥ���Ѵ�.
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



//���� ������ �׸���.
void Display::DrawXLine(Point& pt1 , int len)
{
	for(int i = 0 ; i <len ; i++ )
	{		
		CUtil::Gotoxy(pt1.GetX() + i , pt1.GetY());
		printf("%c",Display::m_cKey);
	}
}
//���� ������ �׸���.
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


