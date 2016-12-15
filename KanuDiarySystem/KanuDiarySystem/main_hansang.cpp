#include <iostream>
#include <string>
#include "KNList.h"
#include "KNItem.h"

using namespace std;

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶ Main
int main()
{
	while(true)
	{
		// 입력
		system("cls");
		item->InputLine();
		system("pause");
		system("cls");
		Sleep(300);

		// 출력
		item->PrintLine();
		system("pause");
		system("cls");
		Sleep(300);

		//// 수정
		//item->ModifyNode();
		//system("pause");
		//system("cls");
		//Sleep(300);

		//// 출력
		//item->PrintLine();
		//system("pause");
		//system("cls");
		//Sleep(300);

		// 삭제
		/*int del_line = 0;
		gotoxy(1, 2);
		printf("삭제할 라인 입력 : ");
		cin >> del_line;
		if( del_line == 0 )*/
			list.DeleteAll();
		/*else
		list.DeleteLine(del_line);*/
		system("pause");
		system("cls");
		Sleep(300);

		// 출력
		item->PrintLine();
		system("pause");
		system("cls");
		Sleep(300);
	}
}
