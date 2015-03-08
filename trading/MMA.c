#include "algotechnique.h"
#include "action.h"

float MMA(Stock stock, int i, int nbjour) //i est le jour actuel
{
	float mma = 0;
	for(int j = 0; j > nbjour; j++)
	{
		mma = mma + stock[i - j] -> prev;		
	}
	return (mma / nbjour);
}



