#include <iostream>
#include <time.h>
#include <string>
#include <list>
#include <vector>
#include "ScheduleMgr.h"
#include "Schedule.h"
#include "Util.h"

using namespace std;

//void CUtil::Gotoxy(int a, int b)
//void textcolor(int color_number);;

#define _FILE_NAME_ "ScheduleList.bin"
// 정보 입력
ScheduleMgr::ScheduleMgr()
{
	fp = fopen(_FILE_NAME_,"a");
	fclose(fp);
}

void ScheduleMgr::SCInsert()
{	
	textcolor(7);
	Schedule buf_p;
	CUtil::Gotoxy(2,5);
	cout << "제목 : ";
	cin.getline(buf_p.subject,sizeof(buf_p.subject));

	CUtil::Gotoxy(2,6);
	cout << "장소 : ";
	cin.getline(buf_p.place, sizeof(buf_p.place));
	
	CUtil::Gotoxy(2,7);
	cout << "날짜 : ";
	cin.getline( buf_p.date, sizeof( buf_p.date));
	
	CUtil::Gotoxy(2,8);
	cout << "내용 : ";
	cin.getline( buf_p.text,sizeof( buf_p.text));

	CUtil::Gotoxy(2,9);
	
	
	FILE *fp;	
	fp = fopen(_FILE_NAME_, "a+" );
	fwrite(&buf_p,sizeof(buf_p),1,fp);
	fclose(fp);
	
	cout << "저장이 완료되었습니다" << endl;
}
void ScheduleMgr::SCDelete()
{
	textcolor(7);	
	int i;
	// 일정을 출력하고 선택을 받자
	vector<Schedule> pp;
	ReadInfo(pp);
	for(i = 0; i<pp.size(); i++)
	{
		CUtil::Gotoxy(3,7+i);
		cout << pp[i].date << " ";
		cout << pp[i].subject << " ";
		cout << endl;
	}

	// 삭제할 파일 정보 입력
	char date_buff[16];
	CUtil::Gotoxy(3,(7+i+1));
	cout << "삭제할 일정 날짜 입력 :" << endl;
	CUtil::Gotoxy(3,(7+i+2));
	cin >> date_buff;
	int check = 0;
	fp = fopen(_FILE_NAME_,"wb");
	for(int j=0;j<pp.size();j++)
	{
		if(strcmp(date_buff,pp[j].date)==0)
		{
			CUtil::Gotoxy(3,(7+i+3));
			cout << "데이터가 삭제되었습니다" << endl;
			++check;
		}
		else
		{
			fwrite(&pp[j],sizeof(pp[j]),1,fp);
		}
	}
	if(check==0)
		cout << "날짜를 잘못 입력하셨습니다."<< endl;
	fclose(fp);	
}

void ScheduleMgr::ShowSCList()
{
	vector<Schedule> p ;
	ReadInfo(p);
	for(int i = 0; i < p.size(); i++)
	{
		cout << p[i].date << " ";
		cout << p[i].subject << " ";
		cout << endl;
	}
}

// 파일 읽어오기
void ScheduleMgr::ReadInfo(vector<Schedule>&p)
{
	//fp = fopen("ScheduleList.bin__","rb");
	fp = fopen(_FILE_NAME_,"rb");
	if(fp == NULL)
	{
		cout << "파일열기실패";
	}
	int i=0;
	int size = 0;

	Schedule data;
	
	while(!feof(fp))
	{
		if(fread(&data,sizeof(Schedule),1,fp) == 1)
		{
			p.push_back(data);
		}
	}

	vector<Schedule> pBuff;
	for(int i = 0; i < p.size() ; i++)
	{
		Schedule p1;
		pBuff.push_back(p1);
	}
	
	if(p.size() > 0)
	{
		// 버블정렬 시작
		for(int i=0;i<((p.size())-1);i++)
		{
			for(int j=0;j<((p.size())-1-i);j++)
			{
				if(0<(strcmp(p[j].date,p[j+1].date)))
				{
					pBuff[0] = p[j];
					pBuff[j] = p[j+1];
					pBuff[j+1] = pBuff[0];
				}
			}
		}
	}
	fclose(fp);
}

// 디스플레이 및 보여주기용 화면 출력

void ScheduleMgr::Backgrounddisplay()
{
	textcolor(8);
	cout << "┌────────────────────────────────────────────────┐" ;
	cout << "│                                                                                                │" ;
	cout << "├──────────────────────────────────┬─────────────┤" ;
	cout << "│                                                                    │                          │" ;
	cout << "├──────────────────────────────────┼─────────────┤" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "│                                                                    │                          │" ;
	cout << "├──────────────────────────────────┴─────────────┤" ;
	cout << "│                                                                                                │" ;
	cout << "├────────────────────────────────────────────────┤" ;
	cout << "│                                                                                                │" ;
	cout << "└────────────────────────────────────────────────┘" ;
}


void ScheduleMgr::calldate()
{
  time_t timer;
  struct tm *t;

  timer = time(NULL);
  t = localtime(&timer);
  CUtil::Gotoxy(2,1);
  printf("Today %d/%d/%d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
}

void ScheduleMgr::scheduleTitle()
{
	CUtil::Gotoxy(73,3);
	textcolor(6);
	cout << "My Scheduler" << endl;
}

void ScheduleMgr::bottom_menu_on()
{
	textcolor(7);
	CUtil::Gotoxy(2,36);
	cout << "  " << "[m] 메인으로" << "   " << "[i] 삽  입" << "   " << "[d] 삭  제" << "   " << endl;
}
void ScheduleMgr::bottom_menu_off()
{
	textcolor(4);
	CUtil::Gotoxy(2,36);
	cout << "♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥" << endl;
}
void ScheduleMgr::top_menu_off2()
{
	textcolor(4);
	CUtil::Gotoxy(2,3);
	cout << "♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥ ♥" << endl;
}

void ScheduleMgr::bottom2()
{
	textcolor(7);
	CUtil::Gotoxy(4,38);
	cout << "일정을 추가하고 있습니다." << endl;
}

void ScheduleMgr::bottom3()
{
	textcolor(7);
	CUtil::Gotoxy(4,38);
	cout << "수행하실 작업을 선택하여 주세요." << endl;
}
void ScheduleMgr::bottom4()
{
	textcolor(7);
	CUtil::Gotoxy(4,38);
	cout << "데이터를 삭제하고 있습니다." << endl;
}




void ScheduleMgr::DecoShow()
{
	textcolor(8);
	CUtil::Gotoxy(0,17);
	cout << "│▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(0,18);
	cout << "│▒▒▒▒▒▒▒▒▒▒▒▒▒▒□□□□□▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(0,19);
	cout << "│▒▒▒▒▒▒▒▒▒▒▒▒□□□□□□□□□□▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(0,20);
	cout << "│▒▒　　　▒▒▒▒▒▒□□□□□□□□□□□□▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(0,21);
	cout << "│▒　　　　　▒▒▒▒□□□□□□□□□□□□□□▒▒▒▒▒　　　▒▒" << endl;
	CUtil::Gotoxy(0,22);
	cout << "│▒　　　　　▒▒▒▒□□□□□　　□□□□□□□▒▒▒▒　　　　　▒" << endl;
	CUtil::Gotoxy(0,23);
	cout << "│▒　　　　　▒▒▒□□□■□□　　□□□■□□□□▒▒▒　　　　　▒" << endl;
	CUtil::Gotoxy(0,24);
	cout << "│※※　　　※※▒▒□□□■□□□□□□□■□□□□▒▒▒　　　　　▒" << endl;
	CUtil::Gotoxy(0,25);
	cout << "│※※※※※※※※▒□□□□■□□□□□■□□□□□▒▒※※　　　※※" << endl;
	CUtil::Gotoxy(0,26);
	cout << "│※※※※※※※※※□□□□□■■■■■□□□□□□▒※※※※※※※※" << endl;
	CUtil::Gotoxy(0,27);
	cout << "│※※※※※※※※※□□□□□□■※※■□□□□□□※※※※※※※※※" << endl;
	CUtil::Gotoxy(0,28);
	cout << "│※※※※※※※※※□□□□□□■※※■□□□□□□※※※※※※※※※" << endl;
	CUtil::Gotoxy(0,29);
	cout << "│※※※※※※※※※▒□□□□□□■■□□□□□□□※※※※※※※※※" << endl;
	CUtil::Gotoxy(0,30);
	cout << "│※※※※※※※※※▒□□□□□□□□□□□□□□▒※※※※※※※※※" << endl;
	CUtil::Gotoxy(0,31);
	cout << "│※※※※※※※※▒▒▒□□□□□□□□□□□□▒▒※※※※※※※※※" << endl;
	CUtil::Gotoxy(0,32);
	cout << "│※※※※※※※▒▒▒▒▒□□□□□□□□□□▒▒▒▒※※※※※※※※" << endl;
	CUtil::Gotoxy(0,33);
	cout << "│▒▒▒▒▒▒▒▒▒▒▒▒▒▒□□□□□□▒▒▒▒▒▒▒※※※※※※▒" << endl;
	CUtil::Gotoxy(0,34);
	cout << "│▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
}
void ScheduleMgr::DecoRight()
{
	textcolor(4);
	CUtil::Gotoxy(72,5);
	cout << "▒※▒※▒※▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,6);
	cout << "※▒※▒※▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,7);
	cout << "▒※▒※▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,8);
	cout << "※▒※▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,9);
	cout << "▒※▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,10);
	cout << "※▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,11);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,12);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,13);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,14);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,15);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,16);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,17);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,18);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,19);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,20);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,21);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,22);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,23);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,24);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,25);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,26);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,27);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,28);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒" << endl;
	CUtil::Gotoxy(72,29);
	cout << "▒▒▒▒▒▒▒▒▒▒▒▒※" << endl;
	CUtil::Gotoxy(72,30);
	cout << "▒▒▒▒▒▒▒▒▒▒▒※▒" << endl;
	CUtil::Gotoxy(72,31);
	cout << "▒▒▒▒▒▒▒▒▒▒※▒※" << endl;
	CUtil::Gotoxy(72,32);
	cout << "▒▒▒▒▒▒▒▒▒※▒※▒" << endl;
	CUtil::Gotoxy(72,33);
	cout << "▒▒▒▒▒▒▒▒※▒※▒※" << endl;
	CUtil::Gotoxy(72,34);
	cout << "▒▒▒▒▒▒▒※▒※▒※▒" << endl;
}


// 기능 및 구현 모음
int ScheduleMgr::move(int NowNum)
{	
	vector<Schedule> ppp;
	ReadInfo(ppp);	

	if(NowNum<(ppp.size()))
	{
		for(int i=0;i<(ppp.size());i++)
		{	
			if(NowNum==i)
			{
				textcolor(6);	
				CUtil::Gotoxy(73,6+i);
				printf("%s %s", ppp[i].date,ppp[i].subject);
				showMainData(ppp,NowNum);
			}
			else
			{	
				textcolor(7);	
				CUtil::Gotoxy(73,6+i);
				printf("%s %s", ppp[i].date,ppp[i].subject);
			}
		}
	}
	
	char key = getch();
	
	switch(key)
	{
	case UP : 
		--NowNum; 
		break;
	case DOWN : printf(" "); 
		++NowNum; 
		break;
	case 'm':
	case 'M':
		return key;
		// 돌아가기
		break;
	case 'i':
		// 삽입
		InsertShowSC();
		ListShowSC();
		break;

	case 'd':
		showDelete();
		ListShowSC();
		// 삭제
		break;
	case 'a':
		// 수정

		break;
	}
	
	if(0>NowNum||NowNum>(ppp.size()))
		NowNum = 0;
	return NowNum;
}
void ScheduleMgr::ListShowSC()
{
	system("cls");
	Backgrounddisplay();
	calldate();
	scheduleTitle();
	int NowNum = 0;
	bottom_menu_on();
	bottom3();
	top_menu_off2();
	DecoShow();
	while(1)
	{
		NowNum = move(NowNum);
		if(toupper((char)NowNum) == 'M') //M 명령어가 들오 오면 종료 시킨다.
		{
			break;
		}
	}
}
void ScheduleMgr::InsertShowSC()
{
	system("cls");
	Backgrounddisplay();
	calldate();
	scheduleTitle();
	bottom_menu_off();
	bottom2();
	top_menu_off2();
	DecoRight();
	
	SCInsert();
}
void ScheduleMgr::showDelete()
{
	system("cls");
	Backgrounddisplay();
	calldate();
	scheduleTitle();
	bottom_menu_off();
	bottom4();
	DecoRight();
	top_menu_off2();
	SCDelete();
}
void ScheduleMgr::showMainData(vector<Schedule>&p, int NowNum)
{
	textcolor(7);	
	CUtil::Gotoxy(3,6);
	cout << "                                             ";
	CUtil::Gotoxy(3,6);
	cout << "날짜 : ";
	cout << p[NowNum].date << endl;
	cout << endl;

	CUtil::Gotoxy(3,7);
	cout << "                                             ";
	CUtil::Gotoxy(3,7);
	cout << "제목 : ";
	cout << p[NowNum].subject << endl;
	cout << endl;

	CUtil::Gotoxy(3,8);
	cout << "                                             ";
	CUtil::Gotoxy(3,8);
	cout << "장소 : ";
	cout << p[NowNum].place << endl;
	cout << endl;
	
	CUtil::Gotoxy(3,9);
	cout << "                                             ";
	CUtil::Gotoxy(3,9);
	cout << "내용 : ";
	cout << p[NowNum].text << endl;
}
void ScheduleMgr::showMainSC()
{
	int y = 19;
	vector<Schedule> ppp;
	ReadInfo(ppp);	
	//for(int i=0;(i<(ppp.size()) && i > 8);i++) //8개 까지 표시한다고생각 하고 수정 하였음.
	CUtil::Gotoxy(71,y++); printf("[%-10s][%-14s]","  날  자","   제  목");
	for(int i=0;i < ((ppp.size() > 8) ? 8:ppp.size()) ;i++)
	{	
		textcolor(FOREGROUND_GREEN);	
		CUtil::Gotoxy(71,y++); printf("[%-10s] %s",ppp[i].date,ppp[i].subject);
		textcolor(7);	
	}
}
void textcolor(int color_number)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}

