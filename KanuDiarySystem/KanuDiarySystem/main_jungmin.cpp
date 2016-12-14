#include <iostream>
#include <stdlib.h>
#include "Util.h"

#include "KNFile.h"
#include "CodeList.h"
#include "Layout.h"

using namespace std;

int main()
{
	Layout::Instance()->InitLayOut();

	Layout::Instance()->DrawCase1();
	//Layout::Instance()->InitLayOut();

	//화면 그리기 테스트.
	
	
	
	//KNFile knFile;
	//knFile.Open("test.txt","r+");
	//string str;
	//knFile.ReadLine(str);
	//cout << str << endl;
	////knFile.WriteLine(string("우리나라 대한민국"));

	//CodeListMgr mgr;
	//mgr.LoadData();
	//mgr.Display();

	//vector<Code*> vec;

	//mgr.GetCodeData("날씨",vec);
	//cout << "날씨 검색 자료 표시." << endl;
	//for(int i = 0 ; i < vec.size() ; i++)
	//{
	//	cout << vec[i]->ToString() << endl;
	//}
	//vec.clear();
	//mgr.GetCodeData("기분",vec);
	//cout << "기분 검색 자료 표시." << endl;
	//for(int i = 0 ; i < vec.size() ; i++)
	//{
	//	cout << vec[i]->ToString() << endl;
	//}




	//Rect ret(0,0,100,40);
	//Rect ret1(0,0,71,3);
	//Rect ret2(70,0,30,3);
	////Rect ret(0,0,50,50);
	//Display::DrawRect(ret);
	//Display::DrawRect(ret1);
	//Display::DrawRect(ret2);

	////for(int i = 0; i < 60 ; i++)
	////{
	////	printf("%d\n",i);
	////}

	//
	//getchar();

	system("pause");
}