#include<iostream>
#include"day.h"
using namespace std;

void main__()
{
	Day s[5][7];
	int day = 1;
	for (int row = 0; row<5; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			if(day-3>0)//수요일일경우
			s[row][col].SetDay(day-3);
			s[row][col].SetColol((Day::eColor)(day%4 + 1));
			//s[row][col].SetColol(Day::white);
			day++;
		}
	}

	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 7; col++)
		{
			if (row == 0)
			{
				if (col == 0)
				{
					s[row][col].DrawRect(col * 9, row * 5-row);
				}
				else
				{
					s[row][col].DrawRect(col * 9-col, row * 5 - row);
				}
			}
			else
			{
				if (col == 0)
				{
					s[row][col].DrawRect(col * 9, row * 5-row);
				}
				else
				{
					s[row][col].DrawRect((col * 9) - col, row * 5 - row);
				}

			}
		}
	}


	system("pause");
}