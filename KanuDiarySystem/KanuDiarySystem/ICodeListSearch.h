//#pragma once
#ifndef _ICODELISTSEARCH_H_
#define _ICODELISTSEARCH_H_


#include "KNNode.h"
#include "CodeItem.h"
#include <vector>
#include <string>
using namespace std;

//class Code;
//CodeList �˻� ������ �ܺο� ���� �ϱ� ���� �������̽�.
class ICodeListSearch
{
public:
	//���� or ���
	virtual int GetCodeData(string mainCode, vector<Code*>& vec) = 0;

};
#endif