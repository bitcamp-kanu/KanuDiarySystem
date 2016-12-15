#include "KNItem.h"
#include <vector>;
#include <iostream>
using namespace std;

#define _ROWOFFSET_ 7

bool TextEditer:: InputLine()
{
	int InputCount = 0;
	char buffer[_MAX_CHAR_];
	Item* pItem = NULL;
	// 입력한 데이터 노드 추가
	while( InputCount++ != _MAX_LINE_ )
	{
		CUtil::Gotoxy(1, (InputCount+_ROWOFFSET_));
		InputCount>9 ? printf("[%d]", InputCount) : printf("[0%d]", InputCount);
		CUtil::Gotoxy(5, (InputCount + _ROWOFFSET_));
		cin.clear();
		cin.getline(buffer, _MAX_CHAR_);
		if(strlen(buffer) == 2 && strcmp(buffer,":q") == 0)
		{
			return false;
		}
		pItem = new Item(buffer);
		m_list.InsertAfter(pItem );
	}
	return true;
}
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶ PrintLine()
void TextEditer :: PrintLine()
{
	int PrintCount = 0;
	m_list.GoHead(); // 머리노드부터 순회
	while( !m_list.IsTail() ) // 꼬리노드 도달하면 루프 종료
	{
		if( !m_list.IsHead() && !m_list.IsTail() )
		{
			Item* pNod = (Item*)m_list.GetAt(); // 현재 노드의 데이터 가져옴
			PrintCount++;
			CUtil::Gotoxy(1, (PrintCount + _ROWOFFSET_));
			PrintCount>9 ? printf("[%d]", PrintCount) : printf("[0%d]", PrintCount);
			CUtil::Gotoxy(5, (PrintCount + _ROWOFFSET_));
			cout << pNod->m_strContents << endl; // 출력
		}
		m_list.GoNext(); // 다음 노드로
	} // while-end
}


void TextEditer::GetDataAll(vector<string>& vec)
{
	int PrintCount = 0;
	m_list.GoHead(); // 머리노드부터 순회
	while( !m_list.IsTail() ) // 꼬리노드 도달하면 루프 종료
	{
		if( !m_list.IsHead() && !m_list.IsTail() )
		{
			Item* pNod = (Item*)m_list.GetAt(); // 현재 노드의 데이터 가져옴
			vec.push_back(pNod->m_strContents);
		}
		m_list.GoNext(); // 다음 노드로
	} // while-end
}


/*
class TextEditer
{
private:
	KNList list;
public :
	
};
*/