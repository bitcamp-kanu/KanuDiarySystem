#pragma once
#include <list>
#include <string>
#include "Diary.h"
#include "base.h"
#include "ICodeListSearch.h"
#include "day.h"
using namespace std;
//���̾ ������ ���� �Ѵ�.
class DiaryMgr : public ICalendDataChanged ,public IDiaryDataSearch
{
private:
	eEditMode m_editMode;
	Diary* m_pCur;
	string m_strFileName;
	list<Diary*> m_rgDiary;
public:
	DiaryMgr(void);
	~DiaryMgr(void);

	void SetEditMode(eEditMode mode);
	eEditMode GetEditMode();

	void AddItem(Diary* data);
	void DeleteItem(Diary* data);
	void LoadFile();
	void SaveFile();
	void Display();
	bool CreateItemDisplay();

	bool InputTitle();
	bool InputWeather();
	bool InputFeel();
	bool InputData();
	bool SaveData();


	//������ �������� ���� �Ѵ�.
	Diary* SetModifyItem(string key);
	Diary* SetNewItem();


	int SearchData(string key ,vector<Diary*>& vec);	
	int DataChanged(Day* before, Day* data);
	

};

