#include <iostream>
#include"CalendarManager.h"
#include <windows.h>
#include <vector>
#include <time.h>
#include "Util.h"
#include <vector>
#include "Layout.h"
#include "Log.h"

using namespace std;
#define white (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN)
#define yellow (FOREGROUND_RED | FOREGROUND_GREEN)
#define sky (FOREGROUND_BLUE | FOREGROUND_GREEN)
#define red (FOREGROUND_RED)

calendarmanager::calendarmanager()
{
	m_piDiaryDataSearch = NULL;
	m_piCalendDataChanged =NULL;

	//m_nRow = m_nCol = 3;
	//m_rgDay[3][3].SetSeleted(true);
	int day = 1;
	m_rgDay[0][0].SetWeek("일요일");
	m_rgDay[0][1].SetWeek("월요일");
	m_rgDay[0][2].SetWeek("화요일");
	m_rgDay[0][3].SetWeek("수요일");
	m_rgDay[0][4].SetWeek("목요일");
	m_rgDay[0][5].SetWeek("금요일");
	m_rgDay[0][6].SetWeek("토요일");

	m_year = 2016;
	m_month = 12;
	initdata(m_year, m_month);

}
calendarmanager::~calendarmanager()
{
}
/* 지정한 년도의 월일에 대한  요일을 구하는 함수 */
int calendarmanager::GetWeekDay(int year, int month, int day)
{
	if (month<3) 
	{
		year -= 1;
		month +=12;
	}
	return ((year + (year/4) - (year/100) + (year/400) + (13*month+8) /5 + day) % 7 ) + 1;

	//int i;
	//int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	//long wday, days_passed;




	///* 그리스도 탄생 원년이후 year의 전 년도 12월말 까지 경과된 날 수를 계산합니다.
	//4, 100, 400을 나눈 것은 윤,평,년 일수를 보정하기 위한 것입니다. */
	//days_passed = (long)(year - 1) * 365 + ((year - 1) / 4) - ((year - 1) / 100) + (((year - 1) / 400));

	///* 지정된 달의 이전월말까지 경과 날 수 */
	///*for(i = 0; i < month - 1; i++)*/
	////days_passed += mdays[i];

	///* 지정된 달의 날자까지의 경과일 수 */
	//days_passed += day;

	///* 요일을 구하기 위하여  7로 나눕니다. 0은 일요일 6은 토요일 */
	//wday = days_passed % 7;
	//return wday;
}
void calendarmanager::Setym(int year, int month)
{

}
void calendarmanager::Dispaly()
{
	for (int row = 0; row < 6; row++)
	{
		for (int col = 0; col < 7; col++)
		{

			if (row == 0)
			{
				if (col == 0)
				{
					m_rgDay[row][col].DrawRect(col * _COLL_, row * _ROWW_ - row);
					m_rgDay[row][col].SetColol(Day::eColor::Red);
				}

				else
				{
					m_rgDay[row][col].DrawRect((col * _COLL_) - col, row * _ROWW_ - row);
				}
			}
			else
			{
				if (col == 0)
				{
					m_rgDay[row][col].DrawRect(col * _COLL_, row * _ROWW_ - row);
					m_rgDay[row][col].SetColol(Day::eColor::Red);
				}
				else
				{
					m_rgDay[row][col].DrawRect((col * _COLL_) - col, row * _ROWW_ - row);
				}
			}
		}
	}
}
void calendarmanager::initdata(int year, int month)
{
	int yyyy,mm,dd;
	CUtil::GetCurTime(yyyy,mm,dd);

	int One[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	m_year = year;
	m_month = month;

	m_week=GetWeekDay(m_year, m_month, 1);

	m_rgDay[0][0].width = _COLL_;
	m_rgDay[0][0].height = _ROWW_;
	m_rgDay[0][1].width = _COLL_;
	m_rgDay[0][1].height = _ROWW_;
	m_rgDay[0][2].width = _COLL_;
	m_rgDay[0][2].height = _ROWW_;
	m_rgDay[0][3].width = _COLL_;
	m_rgDay[0][3].height = _ROWW_;
	m_rgDay[0][4].width = _COLL_;
	m_rgDay[0][4].height = _ROWW_;
	m_rgDay[0][5].width = _COLL_;
	m_rgDay[0][5].height = _ROWW_;
	m_rgDay[0][6].width = _COLL_;
	m_rgDay[0][6].height = _ROWW_;
	//int cnt=1;

	int day = 0;
	for (int row = 1; row<6; row++)
	{
		for (int col = 0; col < 7; col++)
		{	
			
			int val = (day - m_week) + 2 ;
			if (val > 0  & val <= One[mm-1]) 
			{				
				char buff[100];
				sprintf(buff,"%04d%02d%02d",m_year,m_month,val);
				m_rgDay[row][col].SetDay(val);	
				string yyyymmdd(buff);
				if(m_piDiaryDataSearch !=NULL)
				{
					vector<Diary*> vec;
					m_piDiaryDataSearch->SearchData(yyyymmdd,vec);					
					if(vec.size() > 0)
					{
						m_rgDay[row][col].m_pDiary = vec[0];
					}
					else
					{
						m_rgDay[row][col].m_pDiary = NULL;
					}
				}
				else
				{
					m_rgDay[row][col].m_pDiary = NULL;
				}

				m_rgDay[row][col].m_strYYYMMDD = yyyymmdd;
				m_rgDay[row][col].width = _COLL_;
				m_rgDay[row][col].height = _ROWW_;

				if(yyyy != m_year || m_month != mm)
				{
					if(val == 1)
					{
						m_rgDay[m_nRow][m_nCol].SetSeleted(false);
						m_rgDay[row][col].SetSeleted(true);
						if(m_piCalendDataChanged != NULL)
						{
							m_piCalendDataChanged->DataChanged(&m_rgDay[m_nRow][m_nCol],&m_rgDay[row][col]); 
						}
						m_nRow = row ;
						m_nCol = col;
					}
				}
				else if(yyyy == m_year && m_month == mm)
				{
					if(val == dd)
					{
						m_rgDay[m_nRow][m_nCol].SetSeleted(false);
						m_rgDay[row][col].SetSeleted(true);
						if(m_piCalendDataChanged != NULL)
						{
							m_piCalendDataChanged->DataChanged(&m_rgDay[m_nRow][m_nCol],&m_rgDay[row][col]) ;
						}
						m_nRow = row ;
						m_nCol = col;
					}
				}
			}
			else
			{
				m_rgDay[row][col].SetDay(0);
				m_rgDay[row][col].m_strYYYMMDD = "";
				m_rgDay[row][col].m_pDiary  = NULL;
				m_rgDay[row][col].width = _COLL_;
				m_rgDay[row][col].height = _ROWW_;

			}
			day++;
				
			}
		}

}

bool calendarmanager::MoveLeft()
{
	Day* pPOld = NULL;
	pPOld = &m_rgDay[m_nRow][m_nCol];
	if(m_rgDay[m_nRow][m_nCol-1].m_day == 0 && m_nCol >= (0+1))
	{
		Layout::Instance()->SetMessage("이동할수 있는 위치가 아닙니다.");
		Layout::Instance()->DisplayMessage();
		return false;
	}
	pPOld->SetSeleted(false);
	m_rgDay[m_nRow][--m_nCol].SetSeleted(true);
	m_rgDay[m_nRow][m_nCol].DrawRect();

	m_rgDay[m_nRow][m_nCol].DrawRect();
	pPOld->DrawRect();


	if(m_piCalendDataChanged != NULL)
	{
		m_piCalendDataChanged->DataChanged(pPOld,&m_rgDay[m_nRow][m_nCol]);
	}
	return true;
}
bool calendarmanager::MoveRight()
{
	Day* pPOld = NULL;
	pPOld = &m_rgDay[m_nRow][m_nCol];
	if(m_rgDay[m_nRow][m_nCol+1].m_day == 0 && m_nCol >= (6-1))
	{
		Layout::Instance()->SetMessage("이동할수 있는 위치가 아닙니다.");
		Layout::Instance()->DisplayMessage();
		return false;
	}

	pPOld->SetSeleted(false);
	m_rgDay[m_nRow][++m_nCol].SetSeleted(true);
	m_rgDay[m_nRow][m_nCol].DrawRect();

	m_rgDay[m_nRow][m_nCol].DrawRect();
	pPOld->DrawRect();

	if(m_piCalendDataChanged != NULL)
	{
		m_piCalendDataChanged->DataChanged(pPOld,&m_rgDay[m_nRow][m_nCol]);
	}
	return true;
}

bool calendarmanager::MoveUp()
{
	
	Day* pPOld = NULL;
	pPOld = &m_rgDay[m_nRow][m_nCol];
	if(m_rgDay[m_nRow-1][m_nCol].m_day == 0 && m_nRow >= (0+1))
	{
		Layout::Instance()->SetMessage("이동할수 있는 위치가 아닙니다.");
		Layout::Instance()->DisplayMessage();
		return false;
	}
	char buff[1024];
	sprintf(buff,"%d ,%d ", m_nRow , m_nCol);
	CLog::Instance()->WriteLog(string(buff),__FILE__,__LINE__);
	

	pPOld->SetSeleted(false);
	m_rgDay[--m_nRow][m_nCol].SetSeleted(true);
	//m_rgDay[m_nRow][m_nCol].SetSeleted(false);
	m_rgDay[m_nRow][m_nCol].DrawRect();

	m_rgDay[m_nRow][m_nCol].DrawRect();
	pPOld->DrawRect();


	if(m_piCalendDataChanged != NULL)
	{
		m_piCalendDataChanged->DataChanged(pPOld,&m_rgDay[m_nRow][m_nCol]);
	}
	return true;
}
bool calendarmanager::MoveDown()
{
	Day* pPOld = NULL;
	pPOld = &m_rgDay[m_nRow][m_nCol];
	if(m_rgDay[m_nRow+1][m_nCol].m_day == 0 && m_nRow >= (6-1))
	{
		Layout::Instance()->SetMessage("이동할수 있는 위치가 아닙니다.");
		Layout::Instance()->DisplayMessage();
 		return false;
	}
	char buff[1024];
	sprintf(buff,"%d ,%d ", m_nRow , m_nCol);
	CLog::Instance()->WriteLog(string(buff),__FILE__,__LINE__);

	pPOld->SetSeleted(false);
	m_rgDay[++m_nRow][m_nCol].SetSeleted(true);
	m_rgDay[m_nRow][m_nCol].DrawRect();

	m_rgDay[m_nRow][m_nCol].DrawRect();
	pPOld->DrawRect();
	if(m_piCalendDataChanged != NULL)
	{
		m_piCalendDataChanged->DataChanged(pPOld,&m_rgDay[m_nRow][m_nCol]);
	}
	return true;
}
void calendarmanager::SetICalendDataChanged(ICalendDataChanged* piCalendDataChanged)
{
	this->m_piCalendDataChanged = piCalendDataChanged;
}
void calendarmanager::SetIDiaryDataSearch(IDiaryDataSearch* piDiaryDataSearch)
{
	this->m_piDiaryDataSearch = piDiaryDataSearch;
}

Day* calendarmanager::GetSelectDay()
{
	return &m_rgDay[m_nRow][m_nCol];
}


//int main(void)
//{
//	calendarmanager mgr;
//	mgr.Dispaly(); 
//	mgr.initdata(2016, 12);
//	system("cls");
//	mgr.Dispaly();
//
//	mgr.MoveLeft();
//	Sleep(1000);
//	mgr.MoveLeft();
//	Sleep(1000);
//	mgr.MoveRight();
//	Sleep(1000);
//	mgr.MoveRight();
//
//	getch();
//
//}
//void main()
//{
//	Day s[5][7];
//	int day = 1;
//	for (int row = 0; row<5; row++)
//	{
//		for (int col = 0; col < 7; col++)
//		{
//			if (day - 4>0)//수요일일경우
//				s[row][col].SetDay(day - 4);
//			s[row][col].SetColol((Day::eColor)(day % 7 + 1));
//			s[row][1].SetColol(Day::Sky);
//			//s[row][1].SetColol(Day::Sky);
//			day++;
//		}
//	}
//
//	for (int row = 0; row < 5; row++)
//	{
//		for (int col = 0; col < 7; col++)
//		{
//			if (row == 0)
//			{
//				if (col == 0)
//				{
//					s[row][col].DrawRect(col * 9, row * 5 - row);
//				}
//				else
//				{
//					s[row][col].DrawRect(col * 9 - col, row * 5 - row);
//				}
//			}
//			else
//			{
//				if (col == 0)
//				{
//					s[row][col].DrawRect(col * 9, row * 5 - row);
//				}
//				else
//				{
//					s[row][col].DrawRect((col * 9) - col, row * 5 - row);
//				}
//
//			}
//		}
//	}
//
//
//	system("pause");
//}



