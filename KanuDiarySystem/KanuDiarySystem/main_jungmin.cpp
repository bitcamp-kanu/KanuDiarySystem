#include <iostream>
#include <stdlib.h>
#include "Util.h"

#include "KNFile.h"
#include "CodeList.h"
#include "Layout.h"

using namespace std;

int main()
{	
	CUtil::setcursortype(CURSOR_TYPE::NOCURSOR); //Ŀ���� ǥ�� ���� �ʴ´�.
	eKeyCode selectMenu = eKeyCode::eNone;
	eLayOut curLayOut = eLOCalendar;
	Layout::Instance()->InitLayOut();
	while(selectMenu != eKeyCode::eQuit)
	{
		switch(curLayOut)
		{
		case eLayOut::eLOCalendar:
			system("cls");
			Layout::Instance()->DrawCase1();
			Layout::Instance()->DrawToDay();
			Layout::Instance()->DisplayMenuCalendarSelect();
			break;
		case eLayOut::eLODairy:
			system("cls");
			Layout::Instance()->DrawCase2();
			//Layout::Instance()->DrawToDay();
			break;
		case eLayOut::eLOSchedule:
			system("cls");
			Layout::Instance()->DrawCase3();
			Layout::Instance()->DrawToDay();
			Layout::Instance()->DisplayMenuSchedulerSelect();
			break;
		}


		 selectMenu = Layout::Instance()->InputMenu(Point(3,33));
		 CUtil::Gotoxy(0,50);
		 switch(selectMenu)
		 {
		 case eNone:		//= 0x00,
			 break;
		 case eSpecial:		//= 0xe0, //special. 
			  break;
		 case eLEFT:		//= 0x4b, //K Ű���忡�����ڵ�� ���Ұ�
			  break;
		 case eDOWN:		//= 0x50, //P
			  break;
		 case eRIGHT:		//= 0x4d, //M
			  break;
		 case eUP:		//= 0x48, //H
			  break;
		 case ePDOWN:		//= 0x49, //Icase ePDOWN:		//= 0x51,  //Q
			  break;
		 case eDDetail:	//= 'D', //���̾ �󼼺���
			 if(curLayOut == eLOCalendar)
			 {
				 curLayOut = eLODairy;				 
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
		 case eQuit://= 'X'
			 cout << "                            ";
			 CUtil::Gotoxy(0,50);
			 cout << "eQuit";
			  break;
		 }
	}
	

	//getchar();
	//Layout::Instance()->InitLayOut();

	//ȭ�� �׸��� �׽�Ʈ.
	
	int ch = 0x00;

	

	/*while(true)
	{
	ch = getch();
	cout <<  hex << ch << endl;
	}*/
	
	//KNFile knFile;
	//knFile.Open("test.txt","r+");
	//string str;
	//knFile.ReadLine(str);
	//cout << str << endl;
	////knFile.WriteLine(string("�츮���� ���ѹα�"));

	//CodeListMgr mgr;
	//mgr.LoadData();
	//mgr.Display();

	//vector<Code*> vec;

	//mgr.GetCodeData("����",vec);
	//cout << "���� �˻� �ڷ� ǥ��." << endl;
	//for(int i = 0 ; i < vec.size() ; i++)
	//{
	//	cout << vec[i]->ToString() << endl;
	//}
	//vec.clear();
	//mgr.GetCodeData("���",vec);
	//cout << "��� �˻� �ڷ� ǥ��." << endl;
	//for(int i = 0 ; i < vec.size() ; i++)
	//{
	//	cout << vec[i]->ToString() << endl;
	//}




	//Rect ret(0,0,100,40);
	//Rect ret1(0,0,71,3);
	//Rect ret2(70,0,30,3);
	////Rect ret(0,0,50,50);
	//Display::DrawRect(ret);
	//Display::DrawRect(ret1);
	//Display::DrawRect(ret2);

	////for(int i = 0; i < 60 ; i++)
	////{
	////	printf("%d\n",i);
	////}

	//
	//getchar();

	//system("pause");
}