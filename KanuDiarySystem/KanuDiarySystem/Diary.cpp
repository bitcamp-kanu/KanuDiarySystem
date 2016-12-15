#include "Diary.h"
#include <iostream>
#include <string>
#include "Util.h"
#include "KNFile.h"
using namespace std;


Diary::Diary(void)
{
	m_isSave = false;
	//Data 를 초기화 한다.
	memset(m_strKey			,0x00	,sizeof(m_strKey));
	memset(m_strTitle		,0x00	,sizeof(m_strTitle));
	memset(m_strDay			,0x00	,sizeof(m_strDay));
	memset(m_strCreateDate	,0x00	,sizeof(m_strCreateDate));
	memset(m_strFleeCode	,0x00	,sizeof(m_strFleeCode));
	memset(m_strWeadtherCode,0x00	,sizeof(m_strWeadtherCode));
	memset(m_strDiaryPath	,0x00	,sizeof(m_strDiaryPath));

	string crateDate = CUtil::GetCurTime("YYYYMMDDHHMMSS");
	string strDay = CUtil::GetCurTime("YYYYMMDD");
	string strWeek = CUtil::GetWeek();
	string filePath = "C:\\Kanu\\";	
	filePath += CUtil::GetCurTime();
	filePath += ".DB";

	strcpy(m_strKey,crateDate.c_str()); // Key 도 년월일 시분초로 설장 한다.
	strcpy(m_strCreateDate,crateDate.c_str());
	strcpy(m_strDay,strDay.c_str());
	strcpy(m_strDiaryPath,filePath.c_str());
	strcpy(m_strWeek,strWeek.c_str());
}

//복사 생성자.
Diary::Diary(const Diary& diary)
{
	m_isSave = false;
	strcpy(m_strKey			,diary.m_strKey);
	strcpy(m_strTitle		,diary.m_strTitle);
	strcpy(m_strDay			,diary.m_strDay);
	strcpy(m_strCreateDate	,diary.m_strCreateDate);
	strcpy(m_strFleeCode	,diary.m_strFleeCode);
	strcpy(m_strWeadtherCode,diary.m_strWeadtherCode);
	strcpy(m_strDiaryPath	,diary.m_strDiaryPath);
	strcpy(m_strWeek		,diary.m_strWeek);
}

Diary::~Diary(void)
{
}

Diary::Diary(char* strKey,char* strTitle,char* strDay ,char* strCreateDate ,char* strFleeCode,char* strWeadtherCode,char* strDiaryPath,char* week)
{
	m_isSave = false;
	strcpy(m_strKey			,strKey);
	strcpy(m_strTitle		,strTitle);
	strcpy(m_strDay			,strDay);
	strcpy(m_strCreateDate	,strCreateDate);
	strcpy(m_strFleeCode	,strFleeCode);
	strcpy(m_strWeadtherCode,strWeadtherCode);
	strcpy(m_strDiaryPath	,strDiaryPath);
	strcpy(m_strWeek		,week);
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
string Diary::GetTitle()
{
	return string(m_strTitle);
}
string Diary::GetDay()
{
	return string(m_strDay);
}
string Diary::GetCreateDate()
{
	return string(m_strCreateDate);
}
string Diary::GetFleeCode()
{
	return string(m_strFleeCode);
}
string Diary::GetWeadtherCode()
{
	return string(m_strWeadtherCode);
}
string Diary::GetDiaryPath()
{
	return string(m_strDiaryPath);
}
string Diary::GetWeek()
{
	return string(m_strWeek);
}
void Diary::SetTitle(string str)
{
	strcpy(m_strTitle,str.c_str());
}
void Diary::SetDay(string str)
{
	strcpy(m_strDay,str.c_str());
}
void Diary::SetCreateDate(string str)
{
	strcpy(m_strCreateDate,str.c_str());
}
void Diary::SetFleeCode(string str)
{
	strcpy(m_strFleeCode,str.c_str());
}
void Diary::SetWeadtherCode(string str)
{
	strcpy(m_strWeadtherCode,str.c_str());
}
void Diary::SetDiaryPath(string str)
{
	strcpy(m_strDiaryPath,str.c_str());
}
void Diary::SetWeek(string str)
{
	strcpy(m_strWeek,str.c_str());
}

bool Diary::MakeFile() //파일을 생성 한다.
{
	KNFile file;
	return file.Open(m_strDiaryPath,"w"); //파일을 생성해 놓는다.
}
bool Diary::ValidData()
{
	if(strlen(m_strTitle) == 0 || strlen(m_strWeadtherCode) == 0 || strlen(m_strFleeCode) == 0)
	{
		return false;
	}
	return true;
}

bool Diary::SaveTextContent() //Text Content 를 저장 한다.
{
	KNFile file;
	file.Open(m_strDiaryPath,"w");
	vector<string> vec;
	m_oTextEdit.GetDataAll(vec);
	for(int i = 0; i < vec.size() ;i++)
	{
		file.WriteLine(vec[i]);
	}
	return vec.size();
}