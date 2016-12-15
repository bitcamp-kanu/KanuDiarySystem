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
	diarMgr.AddItem(new Diary(("20161212001"),("ù���絥�����Դϴ�."),("20161201"),("20161201121212"),("��� 1 �Դϴ�."),("���� 1 �Դϴ�."),("c:\\Kanu\\20161201.DB"),("������")));
	diarMgr.AddItem(new Diary(("20161212002"),("ù���絥�����Դϴ�."),("20161201"),("20161201121212"),("��� 1 �Դϴ�."),("���� 1 �Դϴ�."),("c:\\Kanu\\20161202.DB"),("������")));
	diarMgr.AddItem(new Diary(("20161212003"),("ù���絥�����Դϴ�."),("20161201"),("20161201121212"),("��� 1 �Դϴ�."),("���� 1 �Դϴ�."),("c:\\Kanu\\20161203.DB"),("������")));
	diarMgr.AddItem(new Diary(("20161212004"),("ù���絥�����Դϴ�."),("20161201"),("20161201121212"),("��� 1 �Դϴ�."),("���� 1 �Դϴ�."),("c:\\Kanu\\20161204.DB"),("������")));
	diarMgr.AddItem(new Diary(("20161212005"),("ù���絥�����Դϴ�."),("20161201"),("20161201121212"),("��� 1 �Դϴ�."),("���� 1 �Դϴ�."),("c:\\Kanu\\20161205.DB"),("������")));
	diarMgr.AddItem(new Diary(("20161212006"),("ù���絥�����Դϴ�."),("20161201"),("20161201121212"),("��� 1 �Դϴ�."),("���� 1 �Դϴ�."),("c:\\Kanu\\20161206.DB"),("������")));
	diarMgr.AddItem(new Diary(("20161212007"),("ù���絥�����Դϴ�."),("20161201"),("20161201121212"),("��� 1 �Դϴ�."),("���� 1 �Դϴ�."),("c:\\Kanu\\20161207.DB"),("������")));
	diarMgr.AddItem(new Diary(("20161212008"),("ù���絥�����Դϴ�."),("20161201"),("20161201121212"),("��� 1 �Դϴ�."),("���� 1 �Դϴ�."),("c:\\Kanu\\20161208.DB"),("������")));
	diarMgr.AddItem(new Diary(("20161212009"),("ù���絥�����Դϴ�."),("20161201"),("20161201121212"),("��� 1 �Դϴ�."),("���� 1 �Դϴ�."),("c:\\Kanu\\20161209.DB"),("������")));
	diarMgr.AddItem(new Diary(("20161212011"),("ù���絥�����Դϴ�."),("20161201"),("20161201121212"),("��� 1 �Դϴ�."),("���� 1 �Դϴ�."),("c:\\Kanu\\20161210.DB"),("������")));
	diarMgr.AddItem(new Diary(("20161212012"),("ù���絥�����Դϴ�."),("20161201"),("20161201121212"),("��� 1 �Դϴ�."),("���� 1 �Դϴ�."),("c:\\Kanu\\20161211.DB"),("������")));
	diarMgr.AddItem(new Diary(("20161212013"),("ù���絥�����Դϴ�."),("20161201"),("20161201121212"),("��� 1 �Դϴ�."),("���� 1 �Դϴ�."),("c:\\Kanu\\20161212.DB"),("������")));
	diarMgr.AddItem(new Diary(("20161212014"),("ù���絥�����Դϴ�."),("20161201"),("20161201121212"),("��� 1 �Դϴ�."),("���� 1 �Դϴ�."),("c:\\Kanu\\20161213.DB"),("������")));
	diarMgr.SaveFile();
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
				break;
			case eLayOut::eLODairy:
				system("cls");
				Layout::Instance()->DrawCase2();
				if(diarMgr.GetEditMode() == eEDCrate)
				{
					diarMgr.CreateItemDisplay();
				}
				else if(selectMenu == eDDetail && selectMenu == eUpdate) // ���� �ϰ� �󼼴� ����.
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
		case ePDOWN:		//= 0x49, //Icase ePDOWN:		//= 0x51,  //Q
			if(curLayOut == eLOCalendar)
			{
				calenderMgr.MoveDown();
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
				curLayOut = eLODairy;	
				diarMgr.SetNewItem();
				diarMgr.SetEditMode(eEDCrate);
				
			}
			else if(curLayOut == eLOSchedule)
			{
				//cout << "������::���θ����(eDCreate)" << endl;
			}
			break;
		case eUpdate:	//= 'U', //���̾ ����.
			if(curLayOut == eLOCalendar)
			{
				curLayOut = eLODairy;		
				//�޷¿��� ������ Ű���� ���� �Ѵ�/
				diarMgr.SetModifyItem("�۾���");
				diarMgr.SetEditMode(eEDUpeate); //����
				
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
	}
	system("pause");
}