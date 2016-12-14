#pragma once
#include <xstring>
using namespace std;
class Diary
{
private:
	char m_strKey[15]; //yyyyMMddHHMMSS
	char m_strTitle[100];
	char m_strDay[8]; //yyyymmdd
	char m_strCreateDate[15]; //yyyyMMddHHMMSS
	char m_strFleeCode[4]; //3자리.
	char m_strWeadtherCode[4]; //3자리.
	char m_strDiaryPath[255];

public:
	string GetKey();
	string GetTitle();
	string GetWeadth();

public:
	Diary(void);
	Diary(const Diary& diary);
	Diary(char* strKey,char* strTitle,char* strDay ,char* strCreateDate ,char* strFleeCode,char* strWeadtherCode,char* strDiaryPath);
	string ToString();
	virtual ~Diary(void);
};

