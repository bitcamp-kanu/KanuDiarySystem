#pragma once
#include "Schedule.h"

#include<iostream>
#include<conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

#define LEFT 75
#define UP 72
#define DOWN 80
#define RIGHT 77
#define ENTER 27

class ScheduleMgr
{
private:
	FILE* fp;
public:
	// ������ ���� �Լ�
	void SCInsert();
	void SCDelete();

public:
	ScheduleMgr();

	// ������ �����κ�
	// ������ ����Ʈ(��¥�� Ÿ��Ʋ�� ���)
	void ShowSCList();
	// ������ �б� �� �������� ��������
	void ReadInfo(vector<Schedule>&p);

	// ���÷��� �� �����ֱ�� ����
	// ��� �̹��� ���
	void Backgrounddisplay();
	// ��� ��¥�� ����Ѵ�
	void calldate();
	// ������ ��� ǥ��
	void scheduleTitle();
	// ������ �޴� ���� ����ȯ
	int move(int NowNum);
	// ������ ���� ���÷��� ����
	void InsertShowSC();
	// �ϴ� �޴� ���
	void bottom_menu_on();
	// �ϴ� �޴� ��� ��� ���
	void bottom_menu_off();
	// ���Ժκ� ��ü ��� ����
	void ListShowSC();
	// �ϴ� ���
	void bottom2();
	void bottom3();
	void bottom4();
	// ���Ժ� �������� ���
	void showMainData(vector<Schedule>&p, int NowNum);
	// ������ ���� ȭ�� ��ºκ�
	void showDelete();
	// ������ �� �ٹ̱�
	void DecoShow();
	// ��ܿ� ��Ʈ�Ѹ���
	void top_menu_off2();
	// ������ ���Ϲ���
	void DecoRight();
};

void textcolor(int color_number);;
