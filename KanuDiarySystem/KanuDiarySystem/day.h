#pragma once
#include "Util.h"
#include <string>
#include "Diary.h"
using namespace std;
class Day
{
public:
	enum eColor { White = 1, Yellow=2, Sky=3, Red=4};
public:
	eColor m_eCol;
	int m_day;
	int m_nX;
	int m_mY;
	int height;
	int width;
	string m_strWeek;
	bool m_isSelect;

	Diary* m_pDiary;

public:
	Day();
	virtual ~Day();
	void DrawRect(int x, int y , bool isOffsest = true);
	void DrawRect();
	void SetDay(int day);
	void SetColol(eColor col);
	void SetWeek(string str);
	bool IsSeleted();
	void SetSeleted(bool bselected);
	//void InputDiary(int year,int month);

};

