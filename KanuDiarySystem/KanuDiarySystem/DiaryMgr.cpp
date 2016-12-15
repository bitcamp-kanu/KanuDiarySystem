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
	//���� ǥ��[ 2016�� 12�� 09�� �ݿ���] ��  ��[ �����Է�  ]���� �ð�[2016-12-06 05:00:21]
	//���� �Է�[���� �Է�                                                             ]
	//[1. ����][2. �帲][3. ��][4. ��] 
	//[�ű�(C)][����(U)][����(D)][���(Esc) [����]
	
	//cout << CUtil::GetCurTime("YYYYMMDD") <<" "<< CUtil::GetWeek() << "\t\t" << CUtil::GetCurTime("YYYYMMDDHHMMSS") << endl;
	CUtil::Gotoxy(3,1);
	cout << "������:["<< CUtil::ToDateFormat(m_pCur->GetDay()) <<" " <<m_pCur->GetWeek() <<"����";	CUtil::Gotoxy(50,1); cout << "]";
	CUtil::Gotoxy(3,2);
	cout << "��  ��:["<< m_pCur->GetTitle();															CUtil::Gotoxy(50,2); cout << "]";
	CUtil::Gotoxy(3,3);
	cout << "��  ��:["<< m_pCur->GetWeadtherCode();													CUtil::Gotoxy(50,3); cout << "]";
	CUtil::Gotoxy(3,4);
	cout << "��  ��:["<< m_pCur->GetWeadtherCode();													CUtil::Gotoxy(50,4); cout << "]";


	CUtil::Gotoxy(3,6);
	cout << "������ �Է�(E) TEXT ����(T) ���� (S) ���� (B)" ;
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
	//			Layout::Instance()->SetMessage("�ʼ��׸� �����͸� �Է� �ϼ���.");
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
	CUtil::setcursortype(CURSOR_TYPE::NORMALCURSOR); //Ŀ���� ǥ�� ���� �ʴ´�.
	char buff[255] = {0};
	CUtil::Gotoxy(11,2);
	cin.getline(buff,255);
	//scanf("%s",buff);
	fflush(stdin);
	fflush(stdout);
	CUtil::setcursortype(CURSOR_TYPE::NOCURSOR); //Ŀ���� ǥ�� ���� �ʴ´�.

	if(this->m_pCur != NULL)
	{
		m_pCur->SetTitle(string(buff));
	}
	return true;
}
bool DiaryMgr::InputWeather()
{
	CUtil::setcursortype(CURSOR_TYPE::NORMALCURSOR); //Ŀ���� ǥ�� ���� �ʴ´�.
	char buff[255] = {0};
	CUtil::Gotoxy(11,3);
	cin.getline(buff,255);
	//scanf("%s",buff);
	fflush(stdin);
	fflush(stdout);
	CUtil::setcursortype(CURSOR_TYPE::NOCURSOR); //Ŀ���� ǥ�� ���� �ʴ´�.
	if(this->m_pCur != NULL)
	{
		this->m_pCur->SetWeadtherCode(string(buff));
	}
	return true;
}
bool DiaryMgr::InputFeel()
{
	CUtil::setcursortype(CURSOR_TYPE::NORMALCURSOR); //Ŀ���� ǥ�� ���� �ʴ´�.
	char buff[255] = {0};
	CUtil::Gotoxy(11,4);
	cin.getline(buff,255);
	//scanf("%s",buff);
	fflush(stdin);
	fflush(stdout);
	CUtil::setcursortype(CURSOR_TYPE::NOCURSOR); //Ŀ���� ǥ�� ���� �ʴ´�.
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
		Layout::Instance()->SetMessage("�ʼ��׸� �����͸� �Է� �ϼ���.");
		Layout::Instance()->DisplayMessage();
	}
	else
	{
		if(!m_pCur->m_isSave)
		{
			AddItem(m_pCur);
			m_pCur->m_isSave = true;
			m_pCur->MakeFile(); //������ ������ ���ÿ� ������ ���� �Ѵ�.
		}
		else
		{
			Layout::Instance()->SetMessage("�̹� ����� ������ �Դϴ�.");
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
// ���̾� ������ ü�ε�.
int DiaryMgr::DataChanged(Day* before, Day* data)
{
	Layout::Instance()->SetMessage("���̾ �����Ͱ� ���� �Ǿ����ϴ�.");
	Layout::Instance()->DisplayMessage();
	return 0;
}