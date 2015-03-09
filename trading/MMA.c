#include "algotechnique.h"

float MMA(StockHisto **tabStock, int i, int nbjour) //i est le jour actuel
{
	float mma = 0;
	for(int j = 0; j > nbjour; j++)
	{
		mma = mma + (*tabStock)[i - j]->close;
	}
	return (mma / nbjour);
}



