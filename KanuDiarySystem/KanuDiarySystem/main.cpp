#include <iostream>
#include <stdlib.h>
#include "Util.h"
#include "KNFile.h"
#include "CodeList.h"
#include "Layout.h"
#include "CalendarManager.h"
#include "Diary.h"
#include "DiaryMgr.h"
#include "ScheduleMgr.h"

using namespace std;

void DisplayDate(int y , int m)
{
	char buff[255];
	sprintf(buff ,"[%04d�� %02d��]",y,m);
	CUtil::Gotoxy(43,1);
	cout << buff ;
}
void NextMonth(int& y , int& m)
{
	y = y + m/12;
	m = m%12 + 1;

}
void PrevMonth(int& y , int& m)
{
	if(m > 1)
	{
		m--;
	}
	else
	{
		y = y - 1;
		m = 12;
	}
}
int main()
{	
	system("mode con:cols=100 lines=42");

	int year = 2016;
	int month = 11; 
	bool bSkipMenuInput = false; //��ɾ� �Է� ��ƾ�� �ǳ� �ڴ�.
	bool bReDraw = true;
	calendarmanager calenderMgr;
	ScheduleMgr scheduleMgr;
	
	DiaryMgr diarMgr;
	diarMgr.LoadFile();
	calenderMgr.SetIDiaryDataSearch(&diarMgr);
	calenderMgr.SetICalendDataChanged(&diarMgr);
	calenderMgr.initdata(year,month);
	calenderMgr.Dispaly();
	DisplayDate(year,month);

	CUtil::setcursortype(CURSOR_TYPE::NOCURSOR); //Ŀ���� ǥ�� ���� �ʴ´�.
	eKeyCode selectMenu = eKeyCode::eNone;
	eLayOut curLayOut = eLOCalendar;

	Layout::Instance()->InitLayOut();
	while(selectMenu != eKeyCode::eQuit)
	{
		if(bReDraw)
		{
			switch(curLayOut)
			{
			case eLayOut::eLOCalendar:
				system("cls");
				Layout::Instance()->DrawCase1();
				Layout::Instance()->DrawToDay();
				calenderMgr.Dispaly();
				Layout::Instance()->DisplayMenuCalendarSelect();
				DisplayDate(year,month);
				diarMgr.DisplayCalender();
				//diarMgr.DisplayItemList();
				scheduleMgr.showMainSC();

				Layout::Instance()->DisplayMessage();
				break;
			case eLayOut::eLODairy:
				system("cls");
				Layout::Instance()->DrawCase2();
				switch(diarMgr.GetEditMode() )
				{
				case eEDCrate: //�ű� �����̸�
					diarMgr.CreateItemDisplay();
					break;
				case eEDUpeate: //�����̸�
				case eEDDisplay:
					diarMgr.CreateItemDisplay();
					break;
				}
				Layout::Instance()->DisplayMessage();
				break;
			case eLayOut::eLOSchedule: 
				system("cls");
				system("mode con:cols=100 lines=42");
				scheduleMgr.ListShowSC();
				bSkipMenuInput = true;
				system("cls");
				curLayOut = eLOCalendar;
				Layout::Instance()->DisplayMessage();
				break;
			}
		}
		bReDraw = true;
		if(!bSkipMenuInput)
		{
			selectMenu = Layout::Instance()->InputMenu(Point(3,33));			
		}
		bSkipMenuInput = false;



		CUtil::Gotoxy(0,50);
		switch(selectMenu)
		{
		case eNone:		//= 0x00,
			break;
		case eSpecial:		//= 0xe0, //special. 
			break;
		case eLEFT:		//= 0x4b, //K Ű���忡�����ڵ�� ���Ұ�
			if(curLayOut == eLOCalendar)
			{
				calenderMgr.MoveLeft();
				bReDraw = false;
			}
			break;
		case eDOWN:		//= 0x50, //P
			if(curLayOut == eLOCalendar)
			{
				calenderMgr.MoveDown();
				bReDraw = false;
			}
			break;
		case eRIGHT:		//= 0x4d, //M
			if(curLayOut == eLOCalendar)
			{
				calenderMgr.MoveRight();
				bReDraw = false;
			}
			break;
		case eUP:		//= 0x48, //H
			if(curLayOut == eLOCalendar)
			{
				calenderMgr.MoveUp();
				bReDraw = false;
			}
			break;
		case ePUP:
			if(curLayOut == eLOCalendar)
			{
				NextMonth(year,month);
				calenderMgr.initdata(year,month);
				DisplayDate(year,month);
				//bReDraw = false;
			}
			break;
		case ePDOWN:		//= 0x49, //Icase ePDOWN:		//= 0x51,  //Q
			if(curLayOut == eLOCalendar)
			{
				PrevMonth(year,month);
				calenderMgr.initdata(year,month);
				DisplayDate(year,month);
				//bReDraw = false;
			}
			break;
		case eDDetail:	//= 'D', //���̾ �󼼺���
			if(curLayOut == eLOCalendar)
			{
				curLayOut = eLODairy;	
				diarMgr.SetEditMode(eEDDisplay);
				cout << "���̾::�󼼺���(eDDetail)" << endl;
			}
			else if(curLayOut == eLOSchedule)
			{
				cout << "������::�󼼺���(eDDetail)" << endl;
			}
			break;
		case eDCreate:	//= 'C', //���̾ ����
			if(curLayOut == eLOCalendar)
			{
				Day* pDay = calenderMgr.GetSelectDay();
				if(pDay->m_pDiary  == NULL)
				{
					curLayOut = eLODairy;	
					diarMgr.SetNewItem();
					diarMgr.SetEditMode(eEDCrate);
				}
				else
				{
					Layout::Instance()->SetMessage("��ϵ� ���� �����Ͱ� �ֽ��ϴ�.");
					Layout::Instance()->DisplayMessage();
				}
			}
			break;
		case eUpdate:	//= 'U', //���̾ ����.
			if(curLayOut == eLOCalendar)
			{
				Day* pDay = calenderMgr.GetSelectDay();
				if(pDay->m_pDiary != NULL)
				{
					curLayOut = eLODairy;		
					//�޷¿��� ������ Ű���� ���� �Ѵ�/
					if(diarMgr.SetModifyItem(pDay->m_pDiary->GetKey()) != NULL)
					{
						diarMgr.SetEditMode(eEDUpeate); //����
					}
					else
					{
						Layout::Instance()->SetMessage("��ġ�ϴ� ���� ���� �����ϴ�.");
						Layout::Instance()->DisplayMessage();
					}

				}
				else
				{
					Layout::Instance()->SetMessage("������ ������ �����ϴ�.");
					Layout::Instance()->DisplayMessage();
				}
			}
			else if(curLayOut == eLOSchedule)
			{
			}
			break;
		case eSchedule:	//= '������ ȭ�� �̵�.'
			if(curLayOut == eLOCalendar)
			{
				curLayOut = eLOSchedule;
			}
			break;
		case eBACK:
			if(curLayOut == eLOSchedule  || curLayOut == eLODairy)
			{
				curLayOut = eLOCalendar;
			}
			break;
		case eSAVE:
			if(curLayOut == eLODairy)
			{
				diarMgr.SaveData();
				bReDraw = false;
			}
			break;
		case eDEidt: //�������Է� (���̾�Է� â�������.)
			if(curLayOut == eLODairy)
			{
				diarMgr.SetEditMode(eEditMode::eEDCrate);
				diarMgr.InputData();
				bReDraw = false;
			}
			break;
		case eDTxtEdit: //���̾ ����.	
			if(curLayOut == eLODairy)
			{
				diarMgr.SetEditMode(eEditMode::eTextEditer);
				diarMgr.TextEdit();
				bReDraw = false;
			}
			break;
		case eQuit://= 'X'
			cout << "                            ";
			CUtil::Gotoxy(0,50);
			cout << "eQuit";
			break;
		}
		selectMenu = eNone; //��ɾ ��������� ���� �ʱ�ȭ �Ѵ�.
	}
	system("pause");

	return 0;
}


//#include <windows.h>
//#include <stdio.h>
//
//int main( void )
//{
//	HANDLE hStdout; 
//	CONSOLE_SCREEN_BUFFER_INFO csbiInfo; 
//	SMALL_RECT srctScrollRect, srctClipRect; 
//	CHAR_INFO chiFill; 
//	COORD coordDest; 
//	int i;
//
//	printf("\nPrinting 20 lines for reference. ");
//	printf("Notice that line 6 is discarded during scrolling.\n");
//	for(i=0; i<=20; i++)
//		printf("%d\n", i);
//
//	hStdout = GetStdHandle(STD_OUTPUT_HANDLE); 
//
//	if (hStdout == INVALID_HANDLE_VALUE) 
//	{
//		printf("GetStdHandle failed with %d\n", GetLastError()); 
//		return 1;
//	}
//
//	// Get the screen buffer size. 
//
//	if (!GetConsoleScreenBufferInfo(hStdout, &csbiInfo)) 
//	{
//		printf("GetConsoleScreenBufferInfo failed %d\n", GetLastError()); 
//		return 1;
//	}
//
//	// The scrolling rectangle is the bottom 15 rows of the 
//	// screen buffer. 
//
//	srctScrollRect.Top = csbiInfo.dwSize.Y - 16; 
//	srctScrollRect.Bottom = csbiInfo.dwSize.Y - 1; 
//	srctScrollRect.Left = 0; 
//	srctScrollRect.Right = csbiInfo.dwSize.X - 1; 
//
//	// The destination for the scroll rectangle is one row up. 
//
//	coordDest.X = 0; 
//	coordDest.Y = csbiInfo.dwSize.Y - 17; 
//
//	// The clipping rectangle is the same as the scrolling rectangle. 
//	// The destination row is left unchanged. 
//
//	srctClipRect = srctScrollRect; 
//
//	// Fill the bottom row with green blanks. 
//
//	chiFill.Attributes = BACKGROUND_GREEN | FOREGROUND_RED; 
//	chiFill.Char.AsciiChar = (char)' '; 
//
//	// Scroll up one line. 
//
//	if(!ScrollConsoleScreenBuffer(  
//		hStdout,         // screen buffer handle 
//		&srctScrollRect, // scrolling rectangle 
//		&srctClipRect,   // clipping rectangle 
//		coordDest,       // top left destination cell 
//		&chiFill))       // fill character and color
//	{
//		printf("ScrollConsoleScreenBuffer failed %d\n", GetLastError()); 
//		return 1;
//	}
//
//	system("pause");
//	return 0;
//}