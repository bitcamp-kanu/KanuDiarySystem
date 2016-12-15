#pragma once
#include "day.h"
#include "ICodeListSearch.h"

#define _ROWW_ 6
#define _COLL_ 11

class calendarmanager
{
private:
	Day m_rgDay[6][7];
	int m_year;
	int m_month;
	int m_week;

	int m_nRow;
	int m_nCol;
	int m_mdays[12];
	ICalendDataChanged* m_piCalendDataChanged;
	IDiaryDataSearch* m_piDiaryDataSearch;
	
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
	//외부에서 ICalendDataChanged값을 받아서 m_piCalendDataChanged에 할당한다
	void SetICalendDataChanged(ICalendDataChanged* piCalendDataChanged);
	void SetIDiaryDataSearch(IDiaryDataSearch* m_piDiaryDataSearch);


};

