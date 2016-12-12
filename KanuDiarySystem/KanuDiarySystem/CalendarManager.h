#pragma once
#include <istream>
#include <string>
using namespace std;
string Days[7]={"일","월","화","수","목","금","토"};
typedef enum eWeek{eSun,eMom,eTue,eWed,eThu,eFri,eSat};
class CalendarItme
{
private:
	int m_nYear;
	int m_nMonth;
	int m_nDay;
	eWeek m_eWeek;
	string m_strDiary; //"YYYYMMDDHHMMSS"
};
class CalendarManager
{
public:
	CalendarManager(void);
	~CalendarManager(void);
};

