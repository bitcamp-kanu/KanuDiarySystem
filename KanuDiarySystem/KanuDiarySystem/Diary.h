#pragma once
#include <string>
#include "KNItem.h"
using namespace std;
class Diary
{
public:
	bool m_isSave;
	TextEditer m_oTextEdit;
public:
	char m_strKey[20]; //yyyyMMddHHMMSS
	char m_strTitle[100];
	char m_strDay[9]; //yyyymmdd
	char m_strCreateDate[15]; //yyyyMMddHHMMSS
	char m_strFleeCode[100]; //3�ڸ�.
	char m_strWeadtherCode[100]; //3�ڸ�.
	char m_strDiaryPath[255];
	char m_strWeek[100]; //yyyymmdd

public:
	string GetKey(); //yyyyMMddHHMMSS
	string GetTitle();
	string GetDay(); //yyyymmdd
	string GetCreateDate(); //yyyyMMddHHMMSS
	string GetFleeCode(); //3�ڸ�.
	string GetWeadtherCode(); //3�ڸ�.
	string GetDiaryPath();
	string GetWeek();
	
	void SetTitle(string str);
	void SetDay(string str); //yyyymmdd
	void SetCreateDate(string str); //yyyyMMddHHMMSS
	void SetFleeCode(string str); //3�ڸ�.
	void SetWeadtherCode(string str); //3�ڸ�.
	void SetDiaryPath(string str);
	void SetWeek(string str);

	bool MakeFile(); //������ ���� �Ѵ�.
	bool SaveTextContent(); //Text Content �� ���� �Ѵ�.

	bool ValidData();

public:
	Diary(void);
	Diary(const Diary& diary);
	Diary(char* strKey,char* strTitle,char* strDay ,char* strCreateDate ,char* strFleeCode,char* strWeadtherCode,char* strDiaryPath,char* week);
	//Diary(char* strKey,char* strTitle,char* strDay ,char* strCreateDate ,char* strFleeCode,char* strWeadtherCode,char* strDiaryPath);
	string ToString();
	virtual ~Diary(void);
};

