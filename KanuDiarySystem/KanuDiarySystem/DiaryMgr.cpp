#include "DiaryMgr.h"
#include <iostream>
#include "Util.h"
#include <list>
#include <string>
using namespace std;

DiaryMgr::DiaryMgr(void)
{
	m_strFileName = "Diary.DB";
	m_pCur = NULL;
}
DiaryMgr::~DiaryMgr(void)
{

}
void DiaryMgr::AddItem(Diary* data)
{	
	m_rgDiary.push_back(data);
}
void DiaryMgr::DeleteItem(Diary* data)
{

}

void DiaryMgr::LoadFile()
{
	Diary* pData = NULL;
	KNFile knFile;
	int nCnt = 0;
	if(knFile.Open(m_strFileName,"rb"))
	{
		while(!knFile.IsEOF())
		{
			pData = new Diary();
			knFile.Read(pData,sizeof(Diary),1);
			m_rgDiary.push_back(pData);
		}
	}
}
void DiaryMgr::SaveFile()
{
	KNFile knFile;
	int nCnt = 0;
	if(knFile.Open(m_strFileName,"wb"))
	{
		list<Diary*>::iterator iter;
		for (iter = m_rgDiary.begin(); iter != m_rgDiary.end(); ++iter)
		{
			knFile.Write((void*)(*iter),sizeof(Diary),1);
		}
	}

}

void DiaryMgr::Display()
{
	list<Diary*>::iterator iter;
	for (iter = m_rgDiary.begin(); iter != m_rgDiary.end(); ++iter)
	{
		cout << (*iter)->ToString() << endl;
	}
}

bool DiaryMgr::CreateItemDisplay()
{
	//���� ǥ��[ 2016�� 12�� 09�� �ݿ���] ��  ��[ �����Է�  ]���� �ð�[2016-12-06 05:00:21]
	//���� �Է�[���� �Է�                                                             ]
	//[1. ����][2. �帲][3. ��][4. ��] 
	//[�ű�(C)][����(U)][����(D)][���(Esc) [����]
	CUtil::Gotoxy(3,1);

	cout << CUtil::GetCurTime("YYYYMMDD") <<" "<< CUtil::GetWeek() << "\t\t" << CUtil::GetCurTime("YYYYMMDDHHMMSS") << endl;
	cout << "   �� ��["<< m_pCur->GetTitle()  <<"                               ]" << endl;
	cout << "   �� ��["<< m_pCur->GetWeadth() <<"                               ]" << endl;
	this->InputTitle();
	this->InputWeather();
	return true;
}
bool DiaryMgr::InputTitle()
{
	CUtil::setcursortype(CURSOR_TYPE::NORMALCURSOR); //Ŀ���� ǥ�� ���� �ʴ´�.
	char buff[255] = {0};
	CUtil::Gotoxy(10,2);
	scanf("%s",buff);
	CUtil::setcursortype(CURSOR_TYPE::NOCURSOR); //Ŀ���� ǥ�� ���� �ʴ´�.
	return true;
}
bool DiaryMgr::InputWeather()
{
	CUtil::setcursortype(CURSOR_TYPE::NORMALCURSOR); //Ŀ���� ǥ�� ���� �ʴ´�.
	char buff[255] = {0};
	CUtil::Gotoxy(10,3);
	scanf("%s",buff);
	CUtil::setcursortype(CURSOR_TYPE::NOCURSOR); //Ŀ���� ǥ�� ���� �ʴ´�.
	return true;
}

Diary* DiaryMgr::SetModifyItem(string key)
{
	list<Diary*>::iterator iter;
	for (iter = m_rgDiary.begin(); iter != m_rgDiary.end(); ++iter)
	{
		if((*iter)->GetKey() == key)
		{
			m_pCur = (*iter);
		}
	}
	return m_pCur;
}
Diary* DiaryMgr::SetNewItem()
{
	m_pCur = new Diary();
	return m_pCur;
}