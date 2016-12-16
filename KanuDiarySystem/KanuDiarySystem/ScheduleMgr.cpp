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
// ���� �Է�
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
	cout << "���� : ";
	cin.getline(buf_p.subject,sizeof(buf_p.subject));

	CUtil::Gotoxy(2,6);
	cout << "��� : ";
	cin.getline(buf_p.place, sizeof(buf_p.place));
	
	CUtil::Gotoxy(2,7);
	cout << "��¥ : ";
	cin.getline( buf_p.date, sizeof( buf_p.date));
	
	CUtil::Gotoxy(2,8);
	cout << "���� : ";
	cin.getline( buf_p.text,sizeof( buf_p.text));

	CUtil::Gotoxy(2,9);
	
	
	FILE *fp;	
	fp = fopen(_FILE_NAME_, "a+" );
	fwrite(&buf_p,sizeof(buf_p),1,fp);
	fclose(fp);
	
	cout << "������ �Ϸ�Ǿ����ϴ�" << endl;
}
void ScheduleMgr::SCDelete()
{
	textcolor(7);	
	int i;
	// ������ ����ϰ� ������ ����
	vector<Schedule> pp;
	ReadInfo(pp);
	for(i = 0; i<pp.size(); i++)
	{
		CUtil::Gotoxy(3,7+i);
		cout << pp[i].date << " ";
		cout << pp[i].subject << " ";
		cout << endl;
	}

	// ������ ���� ���� �Է�
	char date_buff[16];
	CUtil::Gotoxy(3,(7+i+1));
	cout << "������ ���� ��¥ �Է� :" << endl;
	CUtil::Gotoxy(3,(7+i+2));
	cin >> date_buff;
	int check = 0;
	fp = fopen(_FILE_NAME_,"wb");
	for(int j=0;j<pp.size();j++)
	{
		if(strcmp(date_buff,pp[j].date)==0)
		{
			CUtil::Gotoxy(3,(7+i+3));
			cout << "�����Ͱ� �����Ǿ����ϴ�" << endl;
			++check;
		}
		else
		{
			fwrite(&pp[j],sizeof(pp[j]),1,fp);
		}
	}
	if(check==0)
		cout << "��¥�� �߸� �Է��ϼ̽��ϴ�."<< endl;
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

// ���� �о����
void ScheduleMgr::ReadInfo(vector<Schedule>&p)
{
	//fp = fopen("ScheduleList.bin__","rb");
	fp = fopen(_FILE_NAME_,"rb");
	if(fp == NULL)
	{
		cout << "���Ͽ������";
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
		// �������� ����
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

// ���÷��� �� �����ֱ�� ȭ�� ���

void ScheduleMgr::Backgrounddisplay()
{
	textcolor(8);
	cout << "����������������������������������������������������������������������������������������������������" ;
	cout << "��                                                                                                ��" ;
	cout << "����������������������������������������������������������������������������������������������������" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "����������������������������������������������������������������������������������������������������" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "��                                                                    ��                          ��" ;
	cout << "����������������������������������������������������������������������������������������������������" ;
	cout << "��                                                                                                ��" ;
	cout << "����������������������������������������������������������������������������������������������������" ;
	cout << "��                                                                                                ��" ;
	cout << "����������������������������������������������������������������������������������������������������" ;
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
	cout << "  " << "[m] ��������" << "   " << "[i] ��  ��" << "   " << "[d] ��  ��" << "   " << endl;
}
void ScheduleMgr::bottom_menu_off()
{
	textcolor(4);
	CUtil::Gotoxy(2,36);
	cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
}
void ScheduleMgr::top_menu_off2()
{
	textcolor(4);
	CUtil::Gotoxy(2,3);
	cout << "�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��" << endl;
}

void ScheduleMgr::bottom2()
{
	textcolor(7);
	CUtil::Gotoxy(4,38);
	cout << "������ �߰��ϰ� �ֽ��ϴ�." << endl;
}

void ScheduleMgr::bottom3()
{
	textcolor(7);
	CUtil::Gotoxy(4,38);
	cout << "�����Ͻ� �۾��� �����Ͽ� �ּ���." << endl;
}
void ScheduleMgr::bottom4()
{
	textcolor(7);
	CUtil::Gotoxy(4,38);
	cout << "�����͸� �����ϰ� �ֽ��ϴ�." << endl;
}




void ScheduleMgr::DecoShow()
{
	textcolor(8);
	CUtil::Gotoxy(0,17);
	cout << "���ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(0,18);
	cout << "���ƢƢƢƢƢƢƢƢƢƢƢƢƢơ�����ƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(0,19);
	cout << "���ƢƢƢƢƢƢƢƢƢƢƢơ����������ƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(0,20);
	cout << "���Ƣơ������ƢƢƢƢƢơ������������ƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(0,21);
	cout << "���ơ����������ƢƢƢơ��������������ƢƢƢƢơ������Ƣ�" << endl;
	CUtil::Gotoxy(0,22);
	cout << "���ơ����������ƢƢƢơ����ࡡ����������ƢƢƢơ�����������" << endl;
	CUtil::Gotoxy(0,23);
	cout << "���ơ����������ƢƢơ�����ࡡ�����������ƢƢơ�����������" << endl;
	CUtil::Gotoxy(0,24);
	cout << "���ءء������ءآƢơ����������������ƢƢơ�����������" << endl;
	CUtil::Gotoxy(0,25);
	cout << "���ءءءءءءءآơ����������������Ƣơءء������ء�" << endl;
	CUtil::Gotoxy(0,26);
	cout << "���ءءءءءءءءء����������������ơءءءءءءء�" << endl;
	CUtil::Gotoxy(0,27);
	cout << "���ءءءءءءءءء�������ءء�������ءءءءءءءء�" << endl;
	CUtil::Gotoxy(0,28);
	cout << "���ءءءءءءءءء�������ءء�������ءءءءءءءء�" << endl;
	CUtil::Gotoxy(0,29);
	cout << "���ءءءءءءءءآơ���������������ءءءءءءءء�" << endl;
	CUtil::Gotoxy(0,30);
	cout << "���ءءءءءءءءآơ��������������ơءءءءءءءء�" << endl;
	CUtil::Gotoxy(0,31);
	cout << "���ءءءءءءءآƢƢơ������������Ƣơءءءءءءءء�" << endl;
	CUtil::Gotoxy(0,32);
	cout << "���ءءءءءءآƢƢƢƢơ����������ƢƢƢơءءءءءءء�" << endl;
	CUtil::Gotoxy(0,33);
	cout << "���ƢƢƢƢƢƢƢƢƢƢƢƢƢơ������ƢƢƢƢƢƢơءءءءءآ�" << endl;
	CUtil::Gotoxy(0,34);
	cout << "���ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
}
void ScheduleMgr::DecoRight()
{
	textcolor(4);
	CUtil::Gotoxy(72,5);
	cout << "�ơآơآơآƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,6);
	cout << "�آơآơآƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,7);
	cout << "�ơآơآƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,8);
	cout << "�آơآƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,9);
	cout << "�ơآƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,10);
	cout << "�آƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,11);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,12);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,13);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,14);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,15);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,16);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,17);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,18);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,19);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,20);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,21);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,22);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,23);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,24);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,25);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,26);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,27);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,28);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢ�" << endl;
	CUtil::Gotoxy(72,29);
	cout << "�ƢƢƢƢƢƢƢƢƢƢƢơ�" << endl;
	CUtil::Gotoxy(72,30);
	cout << "�ƢƢƢƢƢƢƢƢƢƢơآ�" << endl;
	CUtil::Gotoxy(72,31);
	cout << "�ƢƢƢƢƢƢƢƢƢơآơ�" << endl;
	CUtil::Gotoxy(72,32);
	cout << "�ƢƢƢƢƢƢƢƢơآơآ�" << endl;
	CUtil::Gotoxy(72,33);
	cout << "�ƢƢƢƢƢƢƢơآơآơ�" << endl;
	CUtil::Gotoxy(72,34);
	cout << "�ƢƢƢƢƢƢơآơآơآ�" << endl;
}


// ��� �� ���� ����
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
		// ���ư���
		break;
	case 'i':
		// ����
		InsertShowSC();
		ListShowSC();
		break;

	case 'd':
		showDelete();
		ListShowSC();
		// ����
		break;
	case 'a':
		// ����

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
		if(toupper((char)NowNum) == 'M') //M ��ɾ ��� ���� ���� ��Ų��.
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
	cout << "��¥ : ";
	cout << p[NowNum].date << endl;
	cout << endl;

	CUtil::Gotoxy(3,7);
	cout << "                                             ";
	CUtil::Gotoxy(3,7);
	cout << "���� : ";
	cout << p[NowNum].subject << endl;
	cout << endl;

	CUtil::Gotoxy(3,8);
	cout << "                                             ";
	CUtil::Gotoxy(3,8);
	cout << "��� : ";
	cout << p[NowNum].place << endl;
	cout << endl;
	
	CUtil::Gotoxy(3,9);
	cout << "                                             ";
	CUtil::Gotoxy(3,9);
	cout << "���� : ";
	cout << p[NowNum].text << endl;
}
void ScheduleMgr::showMainSC()
{
	int y = 19;
	vector<Schedule> ppp;
	ReadInfo(ppp);	
	//for(int i=0;(i<(ppp.size()) && i > 8);i++) //8�� ���� ǥ���Ѵٰ���� �ϰ� ���� �Ͽ���.
	CUtil::Gotoxy(71,y++); printf("[%-10s][%-14s]","  ��  ��","   ��  ��");
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

