#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "KNNode.h"
using namespace std;

class Code : public KNNode
{
private:
	string m_strMainCode; //날씨 ro 기분
	string m_strSubCode; //고유키 값으로 사용한다.
	string m_strSubName; //음.
public:
	string GetMainCode();
	string GetSubCode();
	string GetSubName();
	Code(void);
	Code(string strMainCode, string strSubCode ,string strSubName);
	virtual ~Code(void);
	string ToString();
};

