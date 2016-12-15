#include "ScheduleMgr.h"
#include <conio.h>

using namespace std;

int x, y = 0;

void SetCursor(bool bVisible)
{
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = bVisible; // true 보임, false 안보임
    ConsoleCursor.dwSize = 1; // 커서사이즈
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE) , &ConsoleCursor); // 설정
}


// goto와 컬러문은 메인에 있어야 하나보다!!!!
void gotoxy(int a, int b) {
	COORD coord = { a, b };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void textcolor(int color_number)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}

void main__()
{
	SetCursor(false);
	system("mode con:cols=100 lines=42");
	ScheduleMgr p;
	//InsertShowSC();
	p.ListShowSC();
}