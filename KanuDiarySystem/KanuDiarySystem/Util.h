#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
/*
Util 메소드 모음.

*/




class Point
{
private:
	int m_nX;
	int m_nY;

public:
	Point()
	{
		m_nX = m_nY = 0;
	}
	Point(const int& x,const int& y)
	{
		m_nX = x;
		m_nY = y;

	}
	int GetX()
	{
		return m_nX;
	}
	void SetX(const int x)
	{
		m_nX = x;
	}
	int AddX(int x)
	{
		m_nX += x;
	}

	int GetY()
	{
		return m_nY;
	}
	void SetY(const int y)
	{
		m_nY = y;
	}
	int AddY(int y)
	{
		m_nY += y;
	}

	Point& operator+(Point& pt)
	{
		m_nX  = m_nX + pt.GetX();
		m_nY += pt.GetY();
		return (*this);
	}

};

class Rect
{
private:
	int m_nX;
	int m_nY;
	int m_nWidth;
	int m_nHeight;
public:
	Rect(int x,int y, int width, int height)
	{
		m_nX = x;
		m_nY = y;
		m_nWidth = width;
		m_nHeight = height;
	}

	int GetX()
	{
		return m_nX;
	}
	int GetY()
	{
		return m_nY;
	}
	int GetWidth()
	{
		return m_nWidth;
	}
	int GetHeigth()
	{
		return m_nHeight;
	}
	Point GetStaPos()
	{
		return Point(m_nX,m_nY);
	}
};


typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
class CUtil
{
public:
	static void clrscr();
	static void Gotoxy(Point& pt);
	static void Gotoxy(int x, int y);
	static Point WhereXY();
	/*static int wherex();
	static int wherey();*/
	static void setcursortype(CURSOR_TYPE c);
	static void delay(int n);
	
	CUtil(void);
	~CUtil(void);
};


class Display
{
private:
	static char m_cKey;
public:
	//2016.12.13 메소드 추가.
	void static DrawRect(Rect& rect);
	void static DrawRect(Point& pt , Point& pt2);
	//가로 라인은 그린다.
	void static DrawXLine(Point& pt1 , int len);
	//세로 라인을 그린다.`	
	void static DrawYLine(Point& pt1 , int len);

};


#ifndef TURBOC_HEADER
#define TURBOC_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>



#endif // TURBOC_HEADER

