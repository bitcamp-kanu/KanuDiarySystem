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
	//날자 표시[ 2016년 12월 09일 금요일] 날  씨[ 날시입력  ]생성 시간[2016-12-06 05:00:21]
	//제목 입력[제목 입력                                                             ]
	//[1. 맑음][2. 흐림][3. 눈][4. 비] 
	//[신규(C)][수정(U)][삭제(D)][취소(Esc) [저장]
	CUtil::Gotoxy(3,1);

	cout << CUtil::GetCurTime("YYYYMMDD") <<" "<< CUtil::GetWeek() << "\t\t" << CUtil::GetCurTime("YYYYMMDDHHMMSS") << endl;
	cout << "   제 목["<< m_pCur->GetTitle()  <<"                               ]" << endl;
	cout << "   날 씨["<< m_pCur->GetWeadth() <<"                               ]" << endl;
	this->InputTitle();
	this->InputWeather();
	return true;
}
bool DiaryMgr::InputTitle()
{
	CUtil::setcursortype(CURSOR_TYPE::NORMALCURSOR); //커서를 표시 하지 않는다.
	char buff[255] = {0};
	CUtil::Gotoxy(10,2);
	scanf("%s",buff);
	CUtil::setcursortype(CURSOR_TYPE::NOCURSOR); //커서를 표시 하지 않는다.
	return true;
}
bool DiaryMgr::InputWeather()
{
	CUtil::setcursortype(CURSOR_TYPE::NORMALCURSOR); //커서를 표시 하지 않는다.
	char buff[255] = {0};
	CUtil::Gotoxy(10,3);
	scanf("%s",buff);
	CUtil::setcursortype(CURSOR_TYPE::NOCURSOR); //커서를 표시 하지 않는다.
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