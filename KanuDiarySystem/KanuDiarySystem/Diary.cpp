#include "Diary.h"
#include <iostream>
#include <string>
using namespace std;


Diary::Diary(void)
{
	//Data 를 초기화 한다.
	memset(m_strKey			,0x00	,sizeof(m_strKey));
	memset(m_strTitle		,0x00	,sizeof(m_strTitle));
	memset(m_strDay			,0x00	,sizeof(m_strDay));
	memset(m_strCreateDate	,0x00	,sizeof(m_strCreateDate));
	memset(m_strFleeCode	,0x00	,sizeof(m_strFleeCode));
	memset(m_strWeadtherCode,0x00	,sizeof(m_strWeadtherCode));
	memset(m_strDiaryPath	,0x00	,sizeof(m_strDiaryPath));
}

//복사 생성자.
Diary::Diary(const Diary& diary)
{
	strcpy(m_strKey			,diary.m_strKey);
	strcpy(m_strTitle		,diary.m_strTitle);
	strcpy(m_strDay			,diary.m_strDay);
	strcpy(m_strCreateDate	,diary.m_strCreateDate);
	strcpy(m_strFleeCode	,diary.m_strFleeCode);
	strcpy(m_strWeadtherCode,diary.m_strWeadtherCode);
	strcpy(m_strDiaryPath	,diary.m_strDiaryPath);
}

Diary::~Diary(void)
{
}

Diary::Diary(char* strKey,char* strTitle,char* strDay ,char* strCreateDate ,char* strFleeCode,char* strWeadtherCode,char* strDiaryPath)
{
	strcpy(m_strKey			,strKey);
	strcpy(m_strTitle		,strTitle);
	strcpy(m_strDay			,strDay);
	strcpy(m_strCreateDate	,strCreateDate);
	strcpy(m_strFleeCode	,strFleeCode);
	strcpy(m_strWeadtherCode,strWeadtherCode);
	strcpy(m_strDiaryPath	,strDiaryPath);
}

string Diary::ToString()
{
	char buff[1024] = {'0'};
	sprintf(buff,"%s,%s,%s,%s,%s,%s,%s" ,m_strKey,m_strTitle,m_strDay ,m_strCreateDate,m_strWeadtherCode,m_strFleeCode,m_strDiaryPath);
	return string(buff);
}

string Diary::GetKey()
{
	return string(m_strKey);
}

//string Diary::GetKey()
//{
//
//}
string Diary::GetTitle()
{
	return "";
}
string Diary::GetWeadth()
{
	return "";
}
