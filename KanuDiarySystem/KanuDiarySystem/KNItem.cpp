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
	// �Է��� ������ ��� �߰�
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
// �������������������������������������������������������������������� PrintLine()
void TextEditer :: PrintLine()
{
	int PrintCount = 0;
	m_list.GoHead(); // �Ӹ������� ��ȸ
	while( !m_list.IsTail() ) // ������� �����ϸ� ���� ����
	{
		if( !m_list.IsHead() && !m_list.IsTail() )
		{
			Item* pNod = (Item*)m_list.GetAt(); // ���� ����� ������ ������
			PrintCount++;
			CUtil::Gotoxy(1, (PrintCount + _ROWOFFSET_));
			PrintCount>9 ? printf("[%d]", PrintCount) : printf("[0%d]", PrintCount);
			CUtil::Gotoxy(5, (PrintCount + _ROWOFFSET_));
			cout << pNod->m_strContents << endl; // ���
		}
		m_list.GoNext(); // ���� ����
	} // while-end
}


void TextEditer::GetDataAll(vector<string>& vec)
{
	int PrintCount = 0;
	m_list.GoHead(); // �Ӹ������� ��ȸ
	while( !m_list.IsTail() ) // ������� �����ϸ� ���� ����
	{
		if( !m_list.IsHead() && !m_list.IsTail() )
		{
			Item* pNod = (Item*)m_list.GetAt(); // ���� ����� ������ ������
			vec.push_back(pNod->m_strContents);
		}
		m_list.GoNext(); // ���� ����
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