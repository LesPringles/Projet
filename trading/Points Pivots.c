#include "algotechnique.h"
#include "action.h"

// Ca sert pour l'interprétation des graphes

void PIVOT(Stock stock, int i) // i est le jour actuel
{
	float pivot = (stock[i]->prev + stock[i]->high + stock[i]->bid) / 3;// Cours Moyen de la journée
	float S1 =(2*pivot) - stock[i]->high;
	float S2 = pivot - (stock[i]->high - stock[i]->bid);
	float R1 = (2*pivot) - stock[i]->bid;
	float R2 = pivot + (stock[i]->high - stock[i]->bid);
}