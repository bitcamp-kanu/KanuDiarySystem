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
	cout << "[��][��][��][��]����Ű [C]�ű� [D]�� [U]����";CUtil::Gotoxy(x+60,y);cout <<"[A]�����ٰ���";
}


void Layout::DisplayMenuSchedulerSelect(int x /*= 3 1 + 2*/, int y /*= 33*/)
{
	CUtil::Gotoxy(x,y);
	cout << "[C]�ű� [U]���� [R]��ü��� [D]���� [B]�ݱ�" << endl; 
}
void Layout::DisplayMenuDialySelect(int x /*= 3 1 + 2*/, int y /*= 1*/)
{
	CUtil::Gotoxy(x,y);
	cout << "[C]�ű� [U]���� [D]���� [B]�ڷ� [S]����" << endl; 
}

eKeyCode Layout::InputMenu(Point pt)
{
	CUtil::Gotoxy(pt);
	eKeyCode eMenu = eKeyCode::eNone;
	int key;
	while(eMenu == eKeyCode::eNone)
	{
		key = getch();
		if(key == (int)eKeyCode::eSpecial) //Ư��Ű�̸�
		{
			key = getch();
		}
		else //���ĺ� �϶��� ����ڷ� ��ȯ �Ѵ�.
		{
			key = toupper(key);
		}
		switch(key)
		{
		case eLEFT:		//= 0x4b, //K Ű���忡�����ڵ�� ���Ұ�
		case eDOWN:		//= 0x50, //P
		case eRIGHT:	//= 0x4d, //M
		case eUP:		//= 0x48, //H
		case ePUP:		//= 0x49, //I
		case ePDOWN:	//= 0x51,  //Q		
		case eDDetail:	//= 'D', //���̾ �󼼺���
		case eDCreate:	//= 'C', //���̾ ����
		case eSchedule:	//= 'U', //���̾ ����.
		case eUpdate:	//= 'U', //���̾ ����.
		case eBACK:		//= 'B', //�ڷ�.
		case eQuit:		//= 'Q'
		case eSAVE:		//= 'S'
		case eDEidt:	//'E'�������Է� (���̾�Է� â�������.)
		case eDTxtEdit: //'T'���̾ ����.			
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