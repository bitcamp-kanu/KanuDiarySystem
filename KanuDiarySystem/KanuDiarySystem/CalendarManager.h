#pragma once
#include "day.h"
#include "ICodeListSearch.h"
class calendarmanager
{
private:
	Day m_rgDay[6][7];
	int m_year;
	int m_month;
	int m_week;

	int m_nRow;
	int m_nCol;

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
	//�ܺο��� ICalendDataChanged���� �޾Ƽ� m_piCalendDataChanged�� �Ҵ��Ѵ�
	void SetICalendDataChanged(ICalendDataChanged* piCalendDataChanged);
	void SetIDiaryDataSearch(IDiaryDataSearch* m_piDiaryDataSearch);

};

