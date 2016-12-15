#include <iostream>
#include "Schedule.h"
using namespace std;

Schedule::Schedule()
{
	memset(subject, 0, sizeof(subject));
	memset(place, 0, sizeof(place));
	memset(date, 0, sizeof(date));
	memset(text, 0, sizeof(text));
}

Schedule::Schedule(const Schedule& data)
{
	memcpy(subject	,data.subject, sizeof(subject));
	memcpy(place	,data.place	 , sizeof(place));
	memcpy(date		,data.date   , sizeof(date));
	memcpy(text		,data.text	, sizeof(text));
}

Schedule::~Schedule()
{

}