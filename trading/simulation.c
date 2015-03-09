//
//  simulation.c
//  trading
//
//  Created by Charles on 08/03/15.
//  Copyright (c) 2015 Charles. All rights reserved.
//

#include "simulation.h"


// Module de simulation à faire. Prend en parametre le prix d'achat
// Le nombre d'achat à acheter, le titre à acheter
// Doit écrire le tout dans un fichier texte externe.

//si ReadWallet renvoie vraie, alors la simulation existe deja
int ReadWallet(wallet *wallet)
{
    // l'argent posseder
    // l'id de l'action
    // le nombre d'action
    // le prix d'achat
    float argent = .0;
    int StkOwn = 0;
    if (wallet == NULL)
    {
        wallet = malloc(sizeof(wallet));
        wallet->argent = .0;
        wallet->StkOwn = 0;
        wallet->stock = NULL;
    }
    
    FILE* fp = fopen("simulation/portefeuille", "r");
    if (fp)
    {
        // le fichier exist
        // la simulation existe deja
        // lire le fichier
        fscanf(fp, "%f\n%d\n", &argent, &StkOwn);
        
        wallet->argent = argent;
        wallet->StkOwn = StkOwn;
        if (StkOwn == 0)
            return 1;
        
        wallet->stock = malloc(sizeof(Stock) * StkOwn);
        
        int i = 0;
        while((fscanf(fp, "%d;%f;%d\n", &(wallet->stock[i].stockId), &(wallet->stock[i].price), &(wallet->stock[i].nbr)) != EOF)
              && i < StkOwn)
        {
            i++;
        }
        fclose(fp);
        
        return 1;
    }
    else
    {
        // le fichier n'existe pas
        // proposer le debut d'une simulation
        // creation du fichier
        
        return -1;
    }
    
}

void Achat()
{
    
    
}

void Vente()
{
    
    
}