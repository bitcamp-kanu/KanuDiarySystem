#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "KNNode.h"
using namespace std;

class Code : public KNNode
{
private:
	string m_strMainCode; //���� ro ���
	string m_strSubCode; //����Ű ������ ����Ѵ�.
	string m_strSubName; //��.
public:
	string GetMainCode();
	string GetSubCode();
	string GetSubName();
	Code(void);
	Code(string strMainCode, string strSubCode ,string strSubName);
	virtual ~Code(void);
	string ToString();
};

