#include <iostream>
#include"CalendarManager.h"
#include <windows.h>
#include <vector>
#include <time.h>
#include "Util.h"

using namespace std;
#define white (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN)
#define yellow (FOREGROUND_RED | FOREGROUND_GREEN)
#define sky (FOREGROUND_BLUE | FOREGROUND_GREEN)
#define red (FOREGROUND_RED)

calendarmanager::calendarmanager()
{
	m_nRow = m_nCol = 3;
	m_rgDay[3][3].SetSeleted(true);
	int day = 1;
	m_rgDay[0][0].SetWeek("�Ͽ���");
	m_rgDay[0][1].SetWeek("������");
	m_rgDay[0][2].SetWeek("ȭ����");
	m_rgDay[0][3].SetWeek("������");
	m_rgDay[0][4].SetWeek("�����");
	m_rgDay[0][5].SetWeek("�ݿ���");
	m_rgDay[0][6].SetWeek("�����");

	initdata(m_year, m_month);
	m_piDiaryDataSearch = NULL;
	m_piCalendDataChanged =NULL;
	//if(m_piDiaryDataSearch !=NULL)
	///*{
	//m_piDiaryDataSearch->SearchData();
	//}*/

	

}
calendarmanager::~calendarmanager()
{
}
/* ������ �⵵�� ���Ͽ� ����  ������ ���ϴ� �Լ� */
int calendarmanager::GetWeekDay(int year, int month, int day)
{

	int i;
	int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	long wday, days_passed;

	/* �׸����� ź�� �������� year�� �� �⵵ 12���� ���� ����� �� ���� ����մϴ�.
	4, 100, 400�� ���� ���� ��,��,�� �ϼ��� �����ϱ� ���� ���Դϴ�. */
	days_passed = (long)(year - 1) * 365 + ((year - 1) / 4) - ((year - 1) / 100) + (((year - 1) / 400));

	/* ������ ���� ������������ ��� �� �� */
	/*for(i = 0; i < month - 1; i++)*/
		//days_passed += mdays[i];

	/* ������ ���� ���ڱ����� ����� �� */
	days_passed += day;

	/* ������ ���ϱ� ���Ͽ�  7�� �����ϴ�. 0�� �Ͽ��� 6�� ����� */
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
	int a,b,c;
	CUtil::GetCurTime(a,b,c);
	
	
	int day = 0;
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
	int cnt=1;
 	for (int row = 1; row<6; row++)
	{
		for (int col = 0; col < 7; col++)
		{	
			
			
			if (row == 2 && (col%2) == 0)
			{
				m_rgDay[row][col].m_pDiary = new Diary();
				
			} 
 			
			
			if (day - m_week > 0) 
			{
				
					m_rgDay[row][col].SetDay(day-m_week);	

					m_rgDay[row][col].width = _COLL_;
					m_rgDay[row][col].height = _ROWW_;
		
			}
			else
			{
				m_rgDay[row][col].SetDay(0);
				
				
			}day++;
			
			
			
			
		}
	}
	
}

bool calendarmanager::MoveLeft()
{
	Day* pPOld = NULL;
	pPOld = &m_rgDay[m_nRow][m_nCol];

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
//			if (day - 4>0)//�������ϰ��
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
	

