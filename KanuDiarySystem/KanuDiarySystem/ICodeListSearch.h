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
//CodeList 검색 정보를 외부에 전달 하기 위한 인터페이스.
class ICodeListSearch
{
public:
	//날씨 or 기분
	virtual int GetCodeData(string mainCode, vector<Code*>& vec) = 0;
	
};

//class Code;
//달력 에서 데이터가 변경 되었을때 CallBack 로 전달할 인터퍼이스.
class ICalendDataChanged
{
public:
	//날씨 or 기분
	virtual int DataChanged(Day* before, Day* data) = 0;
};

//class Code;
//달력 에서 데이터가 변경 되었을때 CallBack 로 전달할 인터퍼이스.
class IDiaryDataSearch
{
public:
	//검색.
	virtual int SearchData(string key ,vector<Diary*>& vec) = 0;
};
#endif