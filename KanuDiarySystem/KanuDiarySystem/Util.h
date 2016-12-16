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
#include "base.h"
using namespace std;
/*
Util 메소드 모음.
*/
/*
#define FOREGROUND_BLUE      0x0001 // text color contains blue.
#define FOREGROUND_GREEN     0x0002 // text color contains green.
#define FOREGROUND_RED       0x0004 // text color contains red.
#define FOREGROUND_INTENSITY 0x0008 // text color is intensified.
#define BACKGROUND_BLUE      0x0010 // background color contains blue.
#define BACKGROUND_GREEN     0x0020 // background color contains green.
#define BACKGROUND_RED       0x0040 // background color contains red.
#define BACKGROUND_INTENSITY 0x0080 // background color is intensified.
#define COMMON_LVB_LEADING_BYTE    0x0100 // Leading Byte of DBCS
#define COMMON_LVB_TRAILING_BYTE   0x0200 // Trailing Byte of DBCS
#define COMMON_LVB_GRID_HORIZONTAL 0x0400 // DBCS: Grid attribute: top horizontal.
#define COMMON_LVB_GRID_LVERTICAL  0x0800 // DBCS: Grid attribute: left vertical.
#define COMMON_LVB_GRID_RVERTICAL  0x1000 // DBCS: Grid attribute: right vertical.
#define COMMON_LVB_REVERSE_VIDEO   0x4000 // DBCS: Reverse fore/back ground attribute.
#define COMMON_LVB_UNDERSCORE      0x8000 // DBCS: Underscore.

#define COMMON_LVB_SBCSDBCS        0x0300 // SBCS or DBCS flag.
*/




typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
class CUtil
{
private:
	static string format_arg_list(const char *fmt, va_list args);
public:
	static string GetCurTime(const string& str);
	static string GetCurTime();
	static void  GetCurTime(int& y,int& m,int& d);
	static string ToDateFormat(string day);
	static void clrscr();
	static void Gotoxy(Point& pt);
	static void Gotoxy(int x, int y);
	static Point WhereXY();
	static int wherex();
	static int wherey();
	static void setcursortype(CURSOR_TYPE c);
	static void delay(int n);
	//string 를 구분자를 통해서 불리 한다.
	static void Tokenize(const string& str,vector<string>& tokens,const string& delimiters = " ");
	static string GetWeek();
	static void textcolor(int color_number = 7);
	
	
	
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
