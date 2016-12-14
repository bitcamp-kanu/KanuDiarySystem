#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "KNNode.h"
#include "CodeItem.h"
#include "ICodeListSearch.h"
using namespace std;


//�ڵ� ������ txt ���·� ���� �Ѵ�.
class CodeListMgr : public ICodeListSearch
{
private:
	list<Code*> m_rgCodes;
	string m_strFilePath;
public:
	virtual int GetCodeData(string mainCode, vector<Code*>& vec);
	CodeListMgr();
	virtual ~CodeListMgr();

	int LoadData();
	int RemoveAllItem();
	void Display();
};

