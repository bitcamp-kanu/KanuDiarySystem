#include <iostream>
#include <stdlib.h>
#include "Util.h"

#include "KNFile.h"
#include "CodeList.h"
#include "Layout.h"
#include "CalendarManager.h"
#include "Diary.h"
#include "DiaryMgr.h"


using namespace std;

int main()
{	
	bool bReDraw = true;
	calendarmanager calenderMgr;
	DiaryMgr diarMgr;
	//diarMgr.LoadFile();
	diarMgr.Display();

	calenderMgr.initdata(2016,12);
	calenderMgr.Dispaly();
	//	mgr.Dispaly(); 
	//	mgr.initdata(2016, 12)
	//	mgr.Dispaly(); 
	//	mgr.initdata(2016, 12);
	/*
	mgr.AddItem(new Diary("key1","Title","Day","CreateDate","FleeCode","Path"));
	mgr.AddItem(new Diary("key2","Title","Day","CreateDate","FleeCode","Path"));
	mgr.AddItem(new Diary("key3","Title","Day","CreateDate","FleeCode","Path"));
	mgr.AddItem(new Diary("key4","Title","Day","CreateDate","FleeCode","Path"));
	mgr.AddItem(new Diary("key5","Title","Day","CreateDate","FleeCode","Path"));
	mgr.AddItem(new Diary("key6","Title","Day","CreateDate","FleeCode","Path"));
	mgr.AddItem(new Diary("key7","Title","Day","CreateDate","FleeCode","Path"));
	mgr.AddItem(new Diary("key8","Title","Day","CreateDate","FleeCode","Path"));
	mgr.AddItem(new Diary("key9","Title","Day","CreateDate","FleeCode","Path"));
	mgr.AddItem(new Diary("key10","Title","Day","CreateDate","FleeCode","Path"));
	mgr.AddItem(new Diary("key11","Title","Day","CreateDate","FleeCode","Path"));
	mgr.AddItem(new Diary("key12","Title","Day","CreateDate","FleeCode","Path"));
	mgr.SaveFile();
	*/

	CUtil::setcursortype(CURSOR_TYPE::NOCURSOR); //커서를 표시 하지 않는다.
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
				break;
			case eLayOut::eLODairy:
				system("cls");
				Layout::Instance()->DrawCase2();
				if(selectMenu == eDCreate)
				{
					diarMgr.CreateItemDisplay();
				}
				else if(selectMenu == eDDetail && selectMenu == eUpdate) // 수정 하고 상세는 같다.
				{

				}

				//Layout::Instance()->DrawToDay();
				break;
			case eLayOut::eLOSchedule:
				system("cls");
				Layout::Instance()->DrawCase3();
				Layout::Instance()->DrawToDay();
				Layout::Instance()->DisplayMenuSchedulerSelect();
				break;
			}
		}
		bReDraw = true;




		selectMenu = Layout::Instance()->InputMenu(Point(3,33));
		CUtil::Gotoxy(0,50);
		switch(selectMenu)
		{
		case eNone:		//= 0x00,
			break;
		case eSpecial:		//= 0xe0, //special. 
			break;
		case eLEFT:		//= 0x4b, //K 키보드에서이코드는 필할것
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
		case ePDOWN:		//= 0x49, //Icase ePDOWN:		//= 0x51,  //Q
			if(curLayOut == eLOCalendar)
			{
				calenderMgr.MoveDown();
			}
			break;
		case eDDetail:	//= 'D', //다이어리 상세보기
			if(curLayOut == eLOCalendar)
			{
				curLayOut = eLODairy;				 
				cout << "다이어리::상세보기(eDDetail)" << endl;
			}
			else if(curLayOut == eLOSchedule)
			{
				cout << "스케줄::상세보기(eDDetail)" << endl;
			}
			break;
		case eDCreate:	//= 'C', //다이어리 생성
			if(curLayOut == eLOCalendar)
			{
				curLayOut = eLODairy;	
				diarMgr.SetNewItem();
				
			}
			else if(curLayOut == eLOSchedule)
			{
				//cout << "스케줄::새로만들기(eDCreate)" << endl;
			}
			break;
		case eUpdate:	//= 'U', //다이어리 수정.
			if(curLayOut == eLOCalendar)
			{
				//달력에서 가저온 키값을 설정 한다/
				diarMgr.SetModifyItem("작업중");
				curLayOut = eLODairy;		
				
			}
			else if(curLayOut == eLOSchedule)
			{
			}
			break;
		case eSchedule:	//= '스케줄 화면 이동.'
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
				//저장 한다.
			}
			break;
		case eQuit://= 'X'
			cout << "                            ";
			CUtil::Gotoxy(0,50);
			cout << "eQuit";
			break;
		}
	}
	system("pause");
}