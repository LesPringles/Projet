#include "algotechnique.h"

// Ca sert pour l'interprétation des graphes

void PIVOT(Stock **tabStock, int i) // i est le jour actuel
{
	float pivot = (*tabStock)[i]->prev + (*tabStock)[i]->high + (*tabStock)[i]->bid / 3;// Cours Moyen de la journée
	float S1 =(2*pivot) - (*tabStock)[i]->high;
	float S2 = pivot - ((*tabStock)[i]->high - (*tabStock)[i]->bid);
	float R1 = (2*pivot) - (*tabStock)[i]->bid;
	float R2 = pivot + ((*tabStock)[i]->high - (*tabStock)[i]->bid);
}