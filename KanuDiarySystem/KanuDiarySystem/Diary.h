#pragma once
class Diary
{
private:
	char m_strKey[15]; //yyyyMMddHHMMSS
	char m_strTitle[100];
	char m_strDay[8]; //yyyymmdd
	char m_strCreateDate[15]; //yyyyMMddHHMMSS
	char m_strFleeCode[4]; //3ÀÚ¸®.
	char m_strDiaryPath[255];

public:
	Diary(void);
	Diary(const Diary& diary);
	Diary(char* strKey,char* strTitle,char* strDay ,char* strCreateDate ,char* strFleeCode,char* strDiaryPath);


	virtual ~Diary(void);
};

