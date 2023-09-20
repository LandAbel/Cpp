#include <iostream>
#include "MapForLifeGame.h"
using namespace std;

int main()
{
	//TEST CASE 1
	//MapForLifeGame lm(10);
	//TEST CASE 2
	//MapForLifeGame lm(10,12);
	//TEST CASE 3
	//MapForLifeGame lm(10, 0.3f);
	//TEST CASE 4
	MapForLifeGame lm(12,20, 0.2f);
	do
	{
		lm.Display();
		lm.NextGeneration();
	} while (cin.ignore()&&lm.ActualLevel() <= 100 && !lm.Dead);//If you add cin.ignore() there will be no flickering and at every enter there will be only one next generation without it there will be multiple generation when the enter is pressed.

	return system("pause");
}