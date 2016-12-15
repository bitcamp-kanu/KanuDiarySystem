#pragma once
#include <iostream>
#include "Util.h"
using namespace std;

enum eKeyCode 
{
	eNone		= 0x00,
	eSpecial	= 0xe0, //special. 
	eLEFT		= 0x4b, //K 키보드에서이코드는 필할것
	eDOWN		= 0x50, //P
	eRIGHT		= 0x4d, //M
	eUP			= 0x48, //H
	ePUP		= 0x49, //I
	ePDOWN		= 0x51,  //Q
	eDDetail	= 'D', //다이어리 상세보기
	eDCreate	= 'C', //다이어리 생성
	eUpdate		= 'U', //다이어리 수정.
	eSchedule	= 'A', //다이어리 수정.
	eBACK		= 'B', //뒤로
	eSAVE		= 'S', //저장
	eQuit		= 'X',
	eDEidt		= 'E', //데이터입력 (다이어리입력 창에서사용.)
	eDTxtEdit	= 'T', //다이어리 편집.
	//eDSave		= 'S', //다이어리 저장
};

enum eLayOut
{
	eLOCalendar = 0,
	eLODairy = 1,
	eLOSchedule = 2
};

class Layout
{
private:
	string m_strMessage;
	Rect m_ret;//(0,0,100,39);
	Rect m_ret1;//(0,0,100,3);
	Rect m_ret2;//(0,2,70,31);
	Rect m_ret3;//(69,2,31,3);
	Rect m_ret4;//(69,4,31,15);
	Rect m_ret5;//(69,18,31,15);
	Rect m_ret6;//(0,32,100,4);
	Rect m_ret7;//(0,35,100,4);
	Rect m_ret00;//(0,0,100,39);
	Rect m_ret11;//(0,0,100,8);
	Rect m_ret22;//(0,7,100,32);
	Rect m_ret33;//(0,35,100,4);

	static Layout* m_pLayOut;
public:
	Layout(void);
	virtual ~Layout(void);
	
	static Layout* Instance()
	{
		if(Layout::m_pLayOut == NULL)
		{
			Layout::m_pLayOut  = new Layout();
		}
		return Layout::m_pLayOut;
	}	

	void InitLayOut();
	void DrawCase1();
	void DrawCase2();
	void DrawCase3();
	//오늘 날짜를 표시 한다.
	void DrawToDay(int x = 3 /*1 + 2*/, int y = 1);
	void DisplayMenuCalendarSelect(int x = 3 /*1 + 2*/, int y = 33);
	void DisplayMenuSchedulerSelect(int x = 3 /*1 + 2*/, int y = 33);
	void DisplayMenuDialySelect(int x = 3 /*1 + 2*/, int y = 1);

	void SetMessage(string str);
	void DisplayMessage(int x = 36 /*1 + 2*/, int y = 1);

	//키값을 입력 받아서 메뉴 코드로 변환 한다.
	//pt는 포인터 위치.
	eKeyCode InputMenu(Point pt);


};

