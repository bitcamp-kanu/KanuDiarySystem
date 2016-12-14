#pragma once
#include "Util.h"
class Day
{
public:
	enum eColor { White = 1, Yellow=2, Sky=3, Red=4};
private:
	eColor m_eCol;
	int m_day;
	int m_nX;
	int m_mY;
	int height;
	int width;
public:
	Day();
	virtual ~Day();
	void DrawRect(int x,int y);
	void SetDay(int day);
	void SetColol(eColor col);

};

