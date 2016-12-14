#pragma once
#include <list>
#include <string>
#include "Diary.h"

using namespace std;
//���̾ ������ ���� �Ѵ�.
class DiaryMgr
{
private:
	string m_strFileName;
public:
	DiaryMgr(void);
	~DiaryMgr(void);

	void AddItem(Diary* data);
	void DeleteItem(Diary* data);

	void LoadFile();
	void SaveFile();
};

