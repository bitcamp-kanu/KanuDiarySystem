#include <iostream>
#include"CalendarManager.h"
#include <windows.h>

using namespace std;
calendarmanager::calendarmanager()
{
	m_nRow = m_nCol = 3;
	m_rgDay[3][3].SetSeleted(true);
	int day = 1;
	m_rgDay[0][0].SetWeek("일요일");
	m_rgDay[0][1].SetWeek("월요일");
	m_rgDay[0][2].SetWeek("화요일");
	m_rgDay[0][3].SetWeek("수요일");
	m_rgDay[0][4].SetWeek("목요일");
	m_rgDay[0][5].SetWeek("금요일");
	m_rgDay[0][6].SetWeek("토요일");

	initdata(m_year, m_month);
	

}
calendarmanager::~calendarmanager()
{
}
/* 지정한 년도의 월일에 대한  요일을 구하는 함수 */
int calendarmanager::GetWeekDay(int year, int month, int day)
{
	int i;
	int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	long wday, days_passed;

	/* 그리스도 탄생 원년이후 year의 전 년도 12월말 까지 경과된 날 수를 계산합니다.
	4, 100, 400을 나눈 것은 윤,평,년 일수를 보정하기 위한 것입니다. */
	days_passed = (long)(year - 1) * 365 + ((year - 1) / 4) - ((year - 1) / 100) + (((year - 1) / 400));

	/* 지정된 달의 이전월말까지 경과 날 수 */
	for(i = 0; i < month - 1; i++)
		days_passed += mdays[i];

	/* 지정된 달의 날자까지의 경과일 수 */
	days_passed += day;

	/* 요일을 구하기 위하여  7로 나눕니다. 0은 일요일 6은 토요일 */
	wday = days_passed % 7;
	return wday;
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
					m_rgDay[row][col].DrawRect(col * 9, row * 5 - row);
				}
				else
				{
					m_rgDay[row][col].DrawRect(col * 9 - col, row * 5 - row);
				}
			}
			else
			{
				if (col == 0)
				{
					m_rgDay[row][col].DrawRect(col * 9, row * 5 - row);
				}
				else
				{
					m_rgDay[row][col].DrawRect((col * 9) - col, row * 5 - row);
				}

			}
		}
	}
}
void calendarmanager::initdata(int year, int month)
{
	int day = 0;
	m_year = year;
	m_month = month;

	
	m_week=GetWeekDay(m_year, m_month, 1);

 	for (int row = 1; row<6; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			if (day - m_week > 0) 
			{
				m_rgDay[row][col].SetDay(day-m_week);
			
		
			}
			else
			{
				m_rgDay[row][col].SetDay(0);
				
				
			}
			day++;
		}
	}
	
}

bool calendarmanager::MoveLeft()
{
	m_rgDay[m_nRow][m_nCol].SetSeleted(false);
	m_rgDay[m_nRow][m_nCol].DrawRect();

	m_rgDay[m_nRow][--m_nCol].SetSeleted(true);
	m_rgDay[m_nRow][m_nCol].DrawRect();
	return true;
}
bool calendarmanager::MoveRight()
{
	m_rgDay[m_nRow][m_nCol].SetSeleted(false);
	m_rgDay[m_nRow][m_nCol].DrawRect();

	m_rgDay[m_nRow][++m_nCol].SetSeleted(true);
	m_rgDay[m_nRow][m_nCol].DrawRect();
	return true;
}


int main(void)
{
	calendarmanager mgr;
	mgr.Dispaly(); 
	mgr.initdata(2016, 12);
	system("cls");
	mgr.Dispaly();

	mgr.MoveLeft();
	Sleep(1000);
	mgr.MoveLeft();
	Sleep(1000);
	mgr.MoveRight();
	Sleep(1000);
	mgr.MoveRight();

	getch();

}
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
	
