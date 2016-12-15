#pragma once
#include <list>
#include <string>
#include "Diary.h"
#include "base.h"
using namespace std;
//다이어리 정보를 관리 한다.
class DiaryMgr
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


	//수정할 아이템을 설정 한다.
	Diary* SetModifyItem(string key);
	Diary* SetNewItem();
	

	

};

