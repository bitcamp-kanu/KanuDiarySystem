#pragma once
/*���α׷� ��ü���� ����� ���� �� ����.*/

typedef enum  eEditMode
{
	eEDNone		= 0,
	eEDCrate	= 1,
	eEDUpeate	= 2,
	eTextEditer = 3,
	eEDDisplay
};


#define _COL_ERROR_		BACKGROUND_RED|BACKGROUND_GREEN
#define _COL_BACK_		FOREGROUND_GREEN|FOREGROUND_RED|BACKGROUND_GREEN|BACKGROUND_RED
#define _COL_DIARY_		BACKGROUND_GREEN
#define _COL_DEFAULT_	BACKGROUND_INTENSITY|FOREGROUND_INTENSITY