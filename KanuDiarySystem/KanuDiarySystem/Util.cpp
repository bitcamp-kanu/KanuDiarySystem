#include "Util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

char Display::m_cKey = '*';

CUtil::CUtil(void)
{
}


CUtil::~CUtil(void)
{

}


//#include "turboc.h"

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

void CUtil::Tokenize(const string& str,vector<string>& tokens,const string& delimiters)
{
	// 맨 첫 글자가 구분자인 경우 무시
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);
	// 구분자가 아닌 첫 글자를 찾는다
	string::size_type pos     = str.find_first_of(delimiters, lastPos);
	while (string::npos != pos || string::npos != lastPos)
	{		
		tokens.push_back(str.substr(lastPos, pos - lastPos)); // token을 찾았으니 vector에 추가한다
		lastPos = str.find_first_not_of(delimiters, pos); // 구분자를 뛰어넘는다.  "not_of"에 주의하라
		pos = str.find_first_of(delimiters, lastPos); // 다음 구분자가 아닌 글자를 찾는다
	}
}

// 커서의 x 좌표를 조사한다.
int CUtil::wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&BufInfo);
	return BufInfo.dwCursorPosition.X;
}

// 커서의 y좌표를 조사한다.
int CUtil::wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&BufInfo);
	return BufInfo.dwCursorPosition.Y;
}

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

void CUtil::GetCurTime(string key)
{
	static char s[255];
	struct tm *t;
	time_t timer;
	timer = time(NULL);    // 현재 시각을 초 단위로 얻기
	t = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 넣기
	string test;
	if(key == string("YTMMDD"))
	{
		sprintf(s, "%04d-%02d-%02d",t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	}
	else if(key == string("YTMMDDHHMM"))
	{
		sprintf(s, "%04d-%02d-%02d %02d:%02d"
				,t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,t->tm_hour, t->tm_min);
	}
	else if(key == string("YYMMDDHHMMSS"))
	{
		sprintf(s, "%04d-%02d-%02d %02d:%02d:%02d",
			t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
			t->tm_hour, t->tm_min, t->tm_sec
			);
	}
}

#pragma warning(disable:4996)
string CUtil::format_arg_list(const char *fmt, va_list args)
{
	if (!fmt) return "";
	int   result = -1, length = 256;
	char *buffer = 0;
	while (result == -1)
	{
		if (buffer) delete [] buffer;
		buffer = new char [length + 1];
		memset(buffer, 0, length + 1);
		result = _vsnprintf(buffer, length, fmt, args);
		length *= 2;
	}
	std::string s(buffer);
	delete [] buffer;
	return s;
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
		CUtil::Gotoxy(pt1.GetX() , pt1.GetY() + i);
		//printf("%c %d",Display::m_cKey,i);
		printf("%c",Display::m_cKey);
	}
}

void Display::DrawRect(Point& pt ,Point& pt2)
{
	for(int i = 0 ; i <pt2.GetX() ; i++ )
	{	
		int j=pt2.GetY();
		CUtil::Gotoxy(pt.GetX() + i , pt.GetY());
		printf("%c",Display::m_cKey);
		CUtil::Gotoxy(pt.GetX() + i+1 , pt.GetY()+j);
		printf("%c",Display::m_cKey);
	}
	for(int i = 0 ; i < pt2.GetY() ; i++ )
	{	
		int j=pt2.GetX();	
		CUtil::Gotoxy(pt.GetX()  , pt.GetY()+i);
		printf("%c",Display::m_cKey);
		CUtil::Gotoxy(pt.GetX() + j, pt.GetY()+i+1);
		printf("%c",Display::m_cKey);
	}
}

//2016.12.13 메소드 추가.
void Display::DrawRect(Rect& rect)
{
	Display::DrawXLine(rect.GetStaPos(),rect.GetWidth());
	Point newPt = rect.GetStaPos() + Point(0,rect.GetHeigth()-1);
	Display::DrawXLine(newPt,rect.GetWidth());
	
	Display::DrawYLine(rect.GetStaPos(),rect.GetHeigth());
	newPt = rect.GetStaPos() + Point(rect.GetWidth()-1,0);
	Display::DrawYLine(newPt,rect.GetHeigth());
}

