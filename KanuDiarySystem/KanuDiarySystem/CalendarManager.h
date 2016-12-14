#pragma once
#include "day.h"

class calendarmanager
{
private:
	Day m_rgDay[6][7];
	int m_year;
	int m_month;
	int m_week;

	int m_nRow;
	int m_nCol;
	
public:
	calendarmanager();
	~calendarmanager();
	void Setym(int year, int month);
	void Dispaly();
	int GetWeekDay(int year, int month, int day);
	void initdata(int year,int month);

	bool MoveLeft();
	bool MoveRight();
	bool MoveDown();
	bool MoveUp();
	

};

