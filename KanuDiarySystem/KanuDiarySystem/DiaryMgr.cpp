#include "DiaryMgr.h"
#include <iostream>
#include "Util.h"
#include <list>
#include <string>
#include "Layout.h"
using namespace std;

DiaryMgr::DiaryMgr(void)
	:m_editMode(eEDNone)
{
	m_strFileName = "Diary.DB";
	m_pCur = NULL;
}
DiaryMgr::~DiaryMgr(void)
{

}

void DiaryMgr::SetEditMode(eEditMode mode)
{
	m_editMode = mode;
}
eEditMode DiaryMgr::GetEditMode()
{
	return m_editMode;
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
	
	//cout << CUtil::GetCurTime("YYYYMMDD") <<" "<< CUtil::GetWeek() << "\t\t" << CUtil::GetCurTime("YYYYMMDDHHMMSS") << endl;
	CUtil::Gotoxy(3,1);
	cout << "생성일:["<< CUtil::ToDateFormat(m_pCur->GetDay()) <<" " <<m_pCur->GetWeek() <<"요일";	CUtil::Gotoxy(50,1); cout << "]";
	CUtil::Gotoxy(3,2);
	cout << "제  목:["<< m_pCur->GetTitle();															CUtil::Gotoxy(50,2); cout << "]";
	CUtil::Gotoxy(3,3);
	cout << "날  씨:["<< m_pCur->GetWeadtherCode();													CUtil::Gotoxy(50,3); cout << "]";
	CUtil::Gotoxy(3,4);
	cout << "기  분:["<< m_pCur->GetWeadtherCode();													CUtil::Gotoxy(50,4); cout << "]";


	CUtil::Gotoxy(3,6);
	cout << "데이터 입력(E) TEXT 편집(T) 저장 (S) 이전 (B)" ;
	//key = Display::IsSaveMenu(3,5);

	//char key;
	//while(true)
	//{
	//	this->InputTitle();
	//	this->InputWeather();
	//	this->InputFeel();		
	//	key = Display::IsSaveMenu(3,5);
	//	if(key == 'Y')
	//	{
	//		if(!m_pCur->ValidData())
	//		{
	//			Layout::Instance()->SetMessage("필수항목 데이터를 입력 하세요.");
	//			Layout::Instance()->DisplayMessage();
	//			key = 'N';
	//		}
	//	}
	//	if(key == 'Y' || key == 'C')
	//	{
	//		if(key == 'Y')
	//		{
	//			AddItem(m_pCur);
	//			m_pCur->MakeFile();
	//		}
	//		break;
	//	}
	//}
	return true;// (key == 'Y');
}
bool DiaryMgr::InputTitle()
{
	CUtil::setcursortype(CURSOR_TYPE::NORMALCURSOR); //커서를 표시 하지 않는다.
	char buff[255] = {0};
	CUtil::Gotoxy(11,2);
	cin.getline(buff,255);
	//scanf("%s",buff);
	fflush(stdin);
	fflush(stdout);
	CUtil::setcursortype(CURSOR_TYPE::NOCURSOR); //커서를 표시 하지 않는다.

	if(this->m_pCur != NULL)
	{
		m_pCur->SetTitle(string(buff));
	}
	return true;
}
bool DiaryMgr::InputWeather()
{
	CUtil::setcursortype(CURSOR_TYPE::NORMALCURSOR); //커서를 표시 하지 않는다.
	char buff[255] = {0};
	CUtil::Gotoxy(11,3);
	cin.getline(buff,255);
	//scanf("%s",buff);
	fflush(stdin);
	fflush(stdout);
	CUtil::setcursortype(CURSOR_TYPE::NOCURSOR); //커서를 표시 하지 않는다.
	if(this->m_pCur != NULL)
	{
		this->m_pCur->SetWeadtherCode(string(buff));
	}
	return true;
}
bool DiaryMgr::InputFeel()
{
	CUtil::setcursortype(CURSOR_TYPE::NORMALCURSOR); //커서를 표시 하지 않는다.
	char buff[255] = {0};
	CUtil::Gotoxy(11,4);
	cin.getline(buff,255);
	//scanf("%s",buff);
	fflush(stdin);
	fflush(stdout);
	CUtil::setcursortype(CURSOR_TYPE::NOCURSOR); //커서를 표시 하지 않는다.
	if(this->m_pCur != NULL)
	{
		this->m_pCur->SetFleeCode(string(buff));
	}
	return true;
};
bool DiaryMgr::InputData()
{
	this->InputTitle();
	this->InputWeather();
	this->InputFeel();
	return true;
}

bool DiaryMgr::SaveData()
{
	if(m_pCur != NULL && !m_pCur->ValidData())
	{
		Layout::Instance()->SetMessage("필수항목 데이터를 입력 하세요.");
		Layout::Instance()->DisplayMessage();
	}
	else
	{
		if(!m_pCur->m_isSave)
		{
			AddItem(m_pCur);
			m_pCur->m_isSave = true;
			m_pCur->MakeFile(); //데이터 생성과 동시에 파일을 생성 한다.
		}
		else
		{
			Layout::Instance()->SetMessage("이미 저장된 아이템 입니다.");
			Layout::Instance()->DisplayMessage();
		}
	}
	return m_pCur;
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


int DiaryMgr::SearchData(string key ,vector<Diary*>& vec)
{
	list<Diary*>::iterator iter;
	for (iter = m_rgDiary.begin(); iter != m_rgDiary.end(); ++iter)
	{
		if((*iter)->GetDay() == key)
		{
			vec.push_back(new Diary());
		}
	}
	return 0;
}
// 다이어어리 데이터 체인디.
int DiaryMgr::DataChanged(Day* before, Day* data)
{
	Layout::Instance()->SetMessage("다이어리 데이터가 변경 되었습니다.");
	Layout::Instance()->DisplayMessage();
	return 0;
}