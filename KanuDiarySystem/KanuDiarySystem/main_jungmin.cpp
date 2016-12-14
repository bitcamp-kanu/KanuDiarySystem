#include <iostream>
#include <stdlib.h>
#include "Util.h"

#include "KNFile.h"
#include "CodeList.h"
#include "Layout.h"

using namespace std;

int main()
{	
	CUtil::setcursortype(CURSOR_TYPE::NOCURSOR); //커서를 표시 하지 않는다.
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
		 case eLEFT:		//= 0x4b, //K 키보드에서이코드는 필할것
			  break;
		 case eDOWN:		//= 0x50, //P
			  break;
		 case eRIGHT:		//= 0x4d, //M
			  break;
		 case eUP:		//= 0x48, //H
			  break;
		 case ePDOWN:		//= 0x49, //Icase ePDOWN:		//= 0x51,  //Q
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
			 }
			 else if(curLayOut == eLOSchedule)
			 {
				 //cout << "스케줄::새로만들기(eDCreate)" << endl;
			 }
			  break;
		 case eUpdate:	//= 'U', //다이어리 수정.
			 if(curLayOut == eLOCalendar)
			 {
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
		 case eQuit://= 'X'
			 cout << "                            ";
			 CUtil::Gotoxy(0,50);
			 cout << "eQuit";
			  break;
		 }
	}
	

	//getchar();
	//Layout::Instance()->InitLayOut();

	//화면 그리기 테스트.
	
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
	////knFile.WriteLine(string("우리나라 대한민국"));

	//CodeListMgr mgr;
	//mgr.LoadData();
	//mgr.Display();

	//vector<Code*> vec;

	//mgr.GetCodeData("날씨",vec);
	//cout << "날씨 검색 자료 표시." << endl;
	//for(int i = 0 ; i < vec.size() ; i++)
	//{
	//	cout << vec[i]->ToString() << endl;
	//}
	//vec.clear();
	//mgr.GetCodeData("기분",vec);
	//cout << "기분 검색 자료 표시." << endl;
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