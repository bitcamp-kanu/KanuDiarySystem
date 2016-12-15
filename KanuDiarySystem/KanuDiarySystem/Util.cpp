#include "Util.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
#include "Display.h"
using namespace std;

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

string CUtil::GetCurTime(const string& str)
{
	char s[255] = {0};
	struct tm *t;
	time_t timer;
	timer = time(NULL);    // 현재 시각을 초 단위로 얻기
	t = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 넣기
	
	string test;
	if(str == string("YYYYMMDD"))
	{
		sprintf(s, "%04d-%02d-%02d",t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	}
	else if(str == string("YYYYMMDDHHMM"))
	{
		sprintf(s, "%04d-%02d-%02d %02d:%02d"
				,t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,t->tm_hour, t->tm_min);
	}
	else if(str == string("YYYYMMDDHHMMSS"))
	{
		sprintf(s, "%04d-%02d-%02d %02d:%02d:%02d",
			t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
			t->tm_hour, t->tm_min, t->tm_sec
			);
	}	
	return string(s);
}

string CUtil::ToDateFormat(string str)
{
	string result;
	string year;
	string month;
	string day;
	string hh;
	string mm;
	if(str.length() == 8)
	{
		year = str.substr(0,4);
		month = str.substr(4,2);
		day = str.substr(6,2);
		result = year+"-"+month+ "-"+ day;
	}
	else if(str.length() == 12)
	{
		year = str.substr(0,4);
		month = str.substr(4,2);
		day = str.substr(6,2);
		hh  = str.substr(8,2);
		mm = str.substr(10,2);
		result = year+"-"+month+ "-"+ day + " " +hh+ ":" + mm;
	}
	else
	{
		result = str;
	}
	return result;
}
string CUtil::GetWeek()
{
	string week[] = { "일", "월", "화", "수", "목", "금", "토" };
	struct tm *t;
	time_t timer;
	timer = time(NULL);    // 현재 시각을 초 단위로 얻기
	t = localtime(&timer); // 초 단위의 시간을 분리하여 구조체에 넣기
	return week[t->tm_wday];
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





