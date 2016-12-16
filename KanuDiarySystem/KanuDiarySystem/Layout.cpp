#include "Layout.h"
#include "Util.h"
#include "Display.h"
#include <iostream>
using namespace std;

Layout* Layout::m_pLayOut = NULL;

Layout::Layout(void)
	:m_ret(0,0,100,39),
	m_ret1(0,0,100,3),
	m_ret2(0,2,70,31),
	m_ret3(69,2,31,3),
	m_ret4(69,4,31,15),
	m_ret5(69,18,31,15),
	m_ret6(0,32,100,4),
	m_ret7(0,35,100,4),
	m_ret00(0,0,100,39),
	m_ret11(0,0,100,8),
	m_ret22(0,7,100,32),
	m_ret33(0,35,100,4)
{

}


Layout::~Layout(void)
{
}

void Layout::InitLayOut()
{
	system("mode con:cols=120 lines=100");
}
void Layout::DrawCase1()
{
	CUtil::textcolor();
	Display::DrawRect(m_ret);
	Display::DrawRect(m_ret1);
	Display::DrawRect(m_ret2);
	Display::DrawRect(m_ret3);
	Display::DrawRect(m_ret4);
	Display::DrawRect(m_ret5);
	Display::DrawRect(m_ret6);
	Display::DrawRect(m_ret7);
}
void Layout::DrawCase2()
{
	CUtil::textcolor();
	Display::DrawRect(m_ret00);
	Display::DrawRect(m_ret11);
	Display::DrawRect(m_ret22);
	Display::DrawRect(m_ret33);
}
void Layout::DrawCase3()
{
	CUtil::textcolor();
	Display::DrawRect(m_ret);
	Display::DrawRect(m_ret1);
	Display::DrawRect(m_ret2);
	Display::DrawRect(m_ret3);
	Display::DrawRect(m_ret4);
	Display::DrawRect(m_ret5);
	Display::DrawRect(m_ret6);
	Display::DrawRect(m_ret7);
}

void Layout::DrawToDay(int x /*= 3 1 + 2*/, int y /*= 1*/)
{
	CUtil::Gotoxy(x,y);
	cout << CUtil::ToDateFormat(CUtil::GetCurTime("YYYYMMDD")) << " "<<CUtil::GetWeek();
}
void Layout::DisplayMenuCalendarSelect(int x /*= 3 1 + 2*/, int y /*= 33*/)
{
	CUtil::Gotoxy(x,y);
	cout << "[←][→][↑][↓]방향키 [C]신규 [D]상세 [U]수정";CUtil::Gotoxy(x+60,y);cout <<"[A]스케줄관리";
}


void Layout::DisplayMenuSchedulerSelect(int x /*= 3 1 + 2*/, int y /*= 33*/)
{
	CUtil::Gotoxy(x,y);
	cout << "[C]신규 [U]수정 [R]전체목록 [D]삭제 [B]닫기" << endl; 
}
void Layout::DisplayMenuDialySelect(int x /*= 3 1 + 2*/, int y /*= 1*/)
{
	CUtil::Gotoxy(x,y);
	cout << "[C]신규 [U]수정 [D]삭제 [B]뒤로 [S]저장" << endl; 
}

eKeyCode Layout::InputMenu(Point pt)
{
	CUtil::Gotoxy(pt);
	eKeyCode eMenu = eKeyCode::eNone;
	int key;
	while(eMenu == eKeyCode::eNone)
	{
		key = getch();
		if(key == (int)eKeyCode::eSpecial) //특수키이면
		{
			key = getch();
		}
		else //알파벳 일때만 대분자로 변환 한다.
		{
			key = toupper(key);
		}
		switch(key)
		{
		case eLEFT:		//= 0x4b, //K 키보드에서이코드는 필할것
		case eDOWN:		//= 0x50, //P
		case eRIGHT:	//= 0x4d, //M
		case eUP:		//= 0x48, //H
		case ePUP:		//= 0x49, //I
		case ePDOWN:	//= 0x51,  //Q		
		case eDDetail:	//= 'D', //다이어리 상세보기
		case eDCreate:	//= 'C', //다이어리 생성
		case eSchedule:	//= 'U', //다이어리 수정.
		case eUpdate:	//= 'U', //다이어리 수정.
		case eBACK:		//= 'B', //뒤로.
		case eQuit:		//= 'Q'
		case eSAVE:		//= 'S'
		case eDEidt:	//'E'데이터입력 (다이어리입력 창에서사용.)
		case eDTxtEdit: //'T'다이어리 편집.			
			eMenu = (eKeyCode)key;
			break;
		default:
			break;
		}
	}
	return eMenu;
}

void Layout::SetMessage(string str)
{
	m_strMessage = str;
}
void Layout::DisplayMessage(int txtcol , int x/* = 36 1 + 2*/, int y/* = 1*/)
{
	//CUtil::textcolor(txtcol);
	CUtil::Gotoxy(x,y);
	cout << m_strMessage;
	//CUtil::textcolor();
}