#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string>
#include <vector>
#include "KNFile.h"
#include "Display.h"
using namespace std;
/*
Util �޼ҵ� ����.
*/
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
class CUtil
{
private:
	static string format_arg_list(const char *fmt, va_list args);
public:
	static string GetCurTime(const string& str);
	static void GetCurTime(int& yyyy,int& mm , int& dd);
	static void clrscr();
	static void Gotoxy(Point& pt);
	static void Gotoxy(int x, int y);
	static Point WhereXY();
	static int wherex();
	static int wherey();
	static void setcursortype(CURSOR_TYPE c);
	static void delay(int n);
	//string �� �����ڸ� ���ؼ� �Ҹ� �Ѵ�.
	static void Tokenize(const string& str,vector<string>& tokens,const string& delimiters = " ");
	static string GetWeek();
	//"YYYYMMDD" ������ str �� YYYY-MM-DD �������� ���� �Ѵ�.
	static string ToDateFormat(string str);
	
	//static string GetCurrentTime(int a);
	
	//static string format(const char *fmt, ...)	
	//{
	//	va_list args;
	//	va_start(args, fmt);
	//	std::string s = format_arg_list(fmt, args);
	//	va_end(args);
	//	return s;
	//}

	CUtil(void);
	~CUtil(void);
};
