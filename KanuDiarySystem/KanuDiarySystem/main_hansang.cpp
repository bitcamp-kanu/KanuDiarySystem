#include <iostream>
#include <string>
#include "KNList.h"
#include "KNItem.h"

using namespace std;

// �������������������������������������������������������������������� Main
int main()
{
	while(true)
	{
		// �Է�
		system("cls");
		item->InputLine();
		system("pause");
		system("cls");
		Sleep(300);

		// ���
		item->PrintLine();
		system("pause");
		system("cls");
		Sleep(300);

		//// ����
		//item->ModifyNode();
		//system("pause");
		//system("cls");
		//Sleep(300);

		//// ���
		//item->PrintLine();
		//system("pause");
		//system("cls");
		//Sleep(300);

		// ����
		/*int del_line = 0;
		gotoxy(1, 2);
		printf("������ ���� �Է� : ");
		cin >> del_line;
		if( del_line == 0 )*/
			list.DeleteAll();
		/*else
		list.DeleteLine(del_line);*/
		system("pause");
		system("cls");
		Sleep(300);

		// ���
		item->PrintLine();
		system("pause");
		system("cls");
		Sleep(300);
	}
}
