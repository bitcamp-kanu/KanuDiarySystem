//#pragma once
#ifndef _ICODELISTSEARCH_H_
#define _ICODELISTSEARCH_H_


#include "KNNode.h"
#include "CodeItem.h"
#include <vector>
#include <string>
using namespace std;

//class Code;
//CodeList 검색 정보를 외부에 전달 하기 위한 인터페이스.
class ICodeListSearch
{
public:
	//날씨 or 기분
	virtual int GetCodeData(string mainCode, vector<Code*>& vec) = 0;

};
#endif