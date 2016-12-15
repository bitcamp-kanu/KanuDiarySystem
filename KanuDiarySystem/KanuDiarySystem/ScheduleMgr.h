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
	// 데이터 관리 함수
	void SCInsert();
	void SCDelete();

public:
	ScheduleMgr();

	// 데이터 관리부분
	// 데이터 리스트(날짜와 타이틀만 출력)
	void ShowSCList();
	// 데이터 읽기 및 오름차순 버블정렬
	void ReadInfo(vector<Schedule>&p);

	// 디스플레이 및 보여주기용 연동
	// 배경 이미지 출력
	void Backgrounddisplay();
	// 상단 날짜를 출력한다
	void calldate();
	// 스케줄 모양 표시
	void scheduleTitle();
	// 오른쪽 메뉴 선택 색변환
	int move(int NowNum);
	// 스케줄 삽입 디스플레이 모음
	void InsertShowSC();
	// 하단 메뉴 출력
	void bottom_menu_on();
	// 하단 메뉴 대신 모양 출력
	void bottom_menu_off();
	// 도입부분 전체 출력 모음
	void ListShowSC();
	// 하단 장식
	void bottom2();
	void bottom3();
	void bottom4();
	// 도입부 상세페이지 출력
	void showMainData(vector<Schedule>&p, int NowNum);
	// 데이터 삭제 화면 출력부분
	void showDelete();
	// 곰돌이 얼굴 꾸미기
	void DecoShow();
	// 상단에 하트뿌리기
	void top_menu_off2();
	// 오른쪽 패턴무늬
	void DecoRight();
};

void textcolor(int color_number);;
