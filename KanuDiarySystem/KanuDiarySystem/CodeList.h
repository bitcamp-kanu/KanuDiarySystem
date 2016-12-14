#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "KNNode.h"
#include "CodeItem.h"
#include "ICodeListSearch.h"
using namespace std;


//코드 정보는 txt 형태로 저장 한다.
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

