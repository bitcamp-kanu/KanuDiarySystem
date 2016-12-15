//#pragma once
#ifndef _ICODELISTSEARCH_H_
#define _ICODELISTSEARCH_H_

#include "KNNode.h"
#include "CodeItem.h"
#include <vector>
#include <string>
#include "day.h"
#include "Diary.h"
using namespace std;

//class Code;
//CodeList �˻� ������ �ܺο� ���� �ϱ� ���� �������̽�.
class ICodeListSearch
{
public:
	//���� or ���
	virtual int GetCodeData(string mainCode, vector<Code*>& vec) = 0;
	
};

//class Code;
//�޷� ���� �����Ͱ� ���� �Ǿ����� CallBack �� ������ �������̽�.
class ICalendDataChanged
{
public:
	//���� or ���
	virtual int DataChanged(Day* before, Day* data) = 0;
};

//class Code;
//�޷� ���� �����Ͱ� ���� �Ǿ����� CallBack �� ������ �������̽�.
class IDiaryDataSearch
{
public:
	//�˻�.
	virtual int SearchData(string key ,vector<Diary*>& vec) = 0;
};
#endif