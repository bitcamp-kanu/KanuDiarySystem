#include "DiaryMgr.h"
#include <iostream>
#include "Util.h"
#include <list>
#include <string>
#include "Layout.h"
using namespace std;

DiaryMgr::DiaryMgr(void)
	:m_editMode(eEDNone)
	,m_pCalenderSelected(NULL)
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
//���̾ ������ ���� �Ѵ�.
void DiaryMgr::SaveFile()
{
	KNFile knFile;
	int nCnt = 0;
	if(knFile.Open(m_strFileName,"wb"))
	{
		list<Diary*>::iterator iter;
		for (iter = m_rgDiary.begin(); iter != m_rgDiary.end(); ++iter)
		{
			(*iter)->SaveTextContent();
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
			m_pCur->SaveTextContent();
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
		string test = (*iter)->GetDay().substr(0,8) ;
		if(test == key)
		{
			vec.push_back((*iter));
		}
	}
	return 0;
}
// ���̾� ������ ü�ε�.
int DiaryMgr::DataChanged(Day* before, Day* data)
{
	m_pCalenderSelected = data;
	DisplayCalender();
	DisplayItemList();
	return 0;
}

int DiaryMgr::TextEdit()
{	
	if(m_pCur != NULL)
	{
		m_pCur->m_oTextEdit.PrintLine();
		m_pCur->m_oTextEdit.InputLine();
	}
	return 0;
}

void DiaryMgr::DisplayCalender()
{
	if(this->m_pCalenderSelected != NULL)
	{
		CUtil::Gotoxy(70,3);
		cout << m_pCalenderSelected ->m_strYYYMMDD;
		if( m_pCalenderSelected->m_pDiary != NULL)
		{
			int y = 5;
			CUtil::Gotoxy(71,y++); cout << m_pCalenderSelected->m_pDiary->m_strKey; //yyyyMMddHHMMSS
			CUtil::Gotoxy(71,y++); cout << m_pCalenderSelected->m_pDiary->m_strTitle;
			CUtil::Gotoxy(71,y++); cout << m_pCalenderSelected->m_pDiary->m_strDay; //yyyymmdd
			CUtil::Gotoxy(71,y++); cout << m_pCalenderSelected->m_pDiary->m_strCreateDate; //yyyyMMddHHMMSS
			CUtil::Gotoxy(71,y++); cout << m_pCalenderSelected->m_pDiary->m_strFleeCode; //3�ڸ�.
			CUtil::Gotoxy(71,y++); cout << m_pCalenderSelected->m_pDiary->m_strWeadtherCode; //3�ڸ�.
			CUtil::Gotoxy(71,y++); cout << m_pCalenderSelected->m_pDiary->m_strDiaryPath;
			CUtil::Gotoxy(71,y++); cout << m_pCalenderSelected->m_pDiary->m_strWeek; //yyyymmdd
			
		}
		else
		{
			int y = 5;
			CUtil::Gotoxy(70,y++); cout << "                         ";
			CUtil::Gotoxy(70,y++); cout << "                         ";
			CUtil::Gotoxy(70,y++); cout << "                         ";
			CUtil::Gotoxy(70,y++); cout << "                         ";
			CUtil::Gotoxy(70,y++); cout << "                         ";
			CUtil::Gotoxy(70,y++); cout << "                         ";
			CUtil::Gotoxy(70,y++); cout << "                         ";
			CUtil::Gotoxy(70,y++); cout << "                         ";

		}
	}
	
}

void DiaryMgr::DisplayItemList()
{
	int y = 19;
	if(m_pCalenderSelected != NULL)
	{
		string yyyymmdd = m_pCalenderSelected->m_strYYYMMDD;
		
		list<Diary*>::iterator iter;
		for (iter = m_rgDiary.begin(); iter != m_rgDiary.end(); ++iter)
		{
			if((*iter)->GetDay().length() >=6 && yyyymmdd.length() >= 6)
			{
				string test = (*iter)->GetDay().substr(0,6) ;
				if(test == yyyymmdd.substr(0,6))
				{
					CUtil::Gotoxy(71,y++); cout << (*iter)->GetDay()<< " " << (*iter)->GetTitle();
				}
			}
		}
	}
}
