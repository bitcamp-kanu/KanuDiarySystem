#pragma once

#define _FILE_NAME_ "ScheduleList.bin"

class Schedule
{
public:
	char subject[100];
	char place[60];
	char date[16];
	char text[200];

public:
	Schedule(void);
	Schedule(const Schedule& data);
	virtual ~Schedule(void);
};
