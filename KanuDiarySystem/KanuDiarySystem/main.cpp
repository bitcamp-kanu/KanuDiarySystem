#include "ScheduleMgr.h"
#include <conio.h>

using namespace std;

int x, y = 0;

void SetCursor(bool bVisible)
{
    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = bVisible; // true ����, false �Ⱥ���
    ConsoleCursor.dwSize = 1; // Ŀ��������
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE) , &ConsoleCursor); // ����
}


// goto�� �÷����� ���ο� �־�� �ϳ�����!!!!
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