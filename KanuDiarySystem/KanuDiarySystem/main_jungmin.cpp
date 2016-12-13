#include <iostream>
#include <stdlib.h>
#include "Util.h"

using namespace std;

int main()
{

	system("mode con:cols=120 lines=100");


	Rect ret(0,0,100,40);
	Rect ret1(0,0,71,3);
	Rect ret2(70,0,30,3);
	//Rect ret(0,0,50,50);
	Display::DrawRect(ret);
	Display::DrawRect(ret1);
	Display::DrawRect(ret2);

	//for(int i = 0; i < 60 ; i++)
	//{
	//	printf("%d\n",i);
	//}

	
	getchar();

	system("pasue");
}