#pragma once
#include <list>
#include <string>
#include "Diary.h"

using namespace std;
//���̾ ������ ���� �Ѵ�.
class DiaryMgr
{
private:
	Diary* m_pCur;
	string m_strFileName;
	list<Diary*> m_rgDiary;
public:
	DiaryMgr(void);
	~DiaryMgr(void);

	void AddItem(Diary* data);
	void DeleteItem(Diary* data);
	void LoadFile();
	void SaveFile();
	void Display();
	bool CreateItemDisplay();

	bool InputTitle();
	bool InputWeather();

	//������ �������� ���� �Ѵ�.
	Diary* SetModifyItem(string key);
	Diary* SetNewItem();
	

	

};

