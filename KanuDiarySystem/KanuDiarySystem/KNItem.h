#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include "KNList.h"
#include "Util.h"

using namespace std;

#define _MAX_LINE_ 27
#define _MAX_CHAR_ 101

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶ Item Class
class Item : public KNNode
{
public:
	string m_strContents;

public :
	Item() {}
	Item(string str)
	{
		m_strContents = str; // 데이터 저장 변수
	}
	virtual ~Item () {}
};

class TextEditer
{
private:
	KNList m_list;
public :
	bool InputLine();
	void PrintLine();
	void ModifyNode();
	void GetDataAll(vector<string>& vec);
	void AddLine(string str);
	int  GetCount();
};


//Item* item = NULL;
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶ InputLine()
//void Item:: InputLine()
//{
//	int InputCount = 0;
//	//string strItem;
//	char* strItem = new char();
//	// 입력한 데이터 노드 추가
//	//gotoxy(3, 2);
//	//printf("↓↓↓ 내용 입력 ↓↓↓\n");
//	while( InputCount++ != _MAX_LINE_ )
//	{
//		gotoxy(1, (InputCount+3));
//		InputCount>9 ? printf("[%d]", InputCount) : printf("[0%d]", InputCount);
//		gotoxy(5, (InputCount+3));
//		cin.clear();
//		cin.getline(strItem, _MAX_CHAR_);
//
//		
//		item = new Item(strItem);
//		list.InsertAfter(item);
//	}
//}
//// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶ PrintLine()
//void Item :: PrintLine()
//{
//	int PrintCount = 0;
//	list.GoHead(); // 머리노드부터 순회
//	gotoxy(3, 2);
//	printf("↓↓↓ 내용 출력 ↓↓↓\n");
//	while( !list.IsTail() ) // 꼬리노드 도달하면 루프 종료
//	{
//		if( !list.IsHead() && !list.IsTail() )
//		{
//			Item* pNod = (Item*)list.GetAt(); // 현재 노드의 데이터 가져옴
//			PrintCount++;
//			gotoxy(1, (PrintCount+3));
//			PrintCount>9 ? printf("[%d]", PrintCount) : printf("[0%d]", PrintCount);
//			gotoxy(5, (PrintCount+3));
//			cout << pNod->m_strContents << endl; // 출력
//		}
//		list.GoNext(); // 다음 노드로
//	} // while-end
//}
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶ ModifyNode
//void ModifyNode()
//{
//	// 내용 불러오기
//	item->PrintLine();
//
//	int ModifyCount = 0;
//	list.GoHead(); // 머리노드부터 순회
//	gotoxy(3, 2);
//	printf("↓↓↓ 내용 수정 ↓↓↓\n");
//	while( !list.IsTail() )
//	{
//		list.GoNext();
//		if( !list.IsHead() && !list.IsTail() )
//		{
//			ModifyCount++;
//			gotoxy(1, (ModifyCount+3));
//			ModifyCount>9 ? printf("[%d]", ModifyCount) : printf("[0%d]", ModifyCount);
//			gotoxy(5, (ModifyCount+3));
//			cin.clear();
//			cin.getline(strItem, _MAX_CHAR_);
//			item = new Item(strItem);
//			list.ModifyNode(item);
//		}
//	}
//}