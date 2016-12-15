#pragma once
#include <xstring>
using namespace std;
class Diary
{
public:
	bool m_isSave;
private:
	char m_strKey[20]; //yyyyMMddHHMMSS
	char m_strTitle[100];
	char m_strDay[8]; //yyyymmdd
	char m_strCreateDate[15]; //yyyyMMddHHMMSS
	char m_strFleeCode[4]; //3磊府.
	char m_strWeadtherCode[4]; //3磊府.
	char m_strDiaryPath[255];
	char m_strWeek[5]; //yyyymmdd

public:
	string GetKey(); //yyyyMMddHHMMSS
	string GetTitle();
	string GetDay(); //yyyymmdd
	string GetCreateDate(); //yyyyMMddHHMMSS
	string GetFleeCode(); //3磊府.
	string GetWeadtherCode(); //3磊府.
	string GetDiaryPath();
	string GetWeek();
	
	void SetTitle(string str);
	void SetDay(string str); //yyyymmdd
	void SetCreateDate(string str); //yyyyMMddHHMMSS
	void SetFleeCode(string str); //3磊府.
	void SetWeadtherCode(string str); //3磊府.
	void SetDiaryPath(string str);
	void SetWeek(string str);

	bool MakeFile(); //颇老阑 积己 茄促.

	bool ValidData();

public:
	Diary(void);
	Diary(const Diary& diary);
	Diary(char* strKey,char* strTitle,char* strDay ,char* strCreateDate ,char* strFleeCode,char* strWeadtherCode,char* strDiaryPath,char* week);
	//Diary(char* strKey,char* strTitle,char* strDay ,char* strCreateDate ,char* strFleeCode,char* strWeadtherCode,char* strDiaryPath);
	string ToString();
	virtual ~Diary(void);
};

