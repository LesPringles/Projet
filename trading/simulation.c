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
int ReadWallet(Wallet *wallet)
{
    // l'argent posseder
    // l'id de l'action
    // le nombre d'action
    // le prix d'achat
    float money = .0;
    int stkOwn = 0;
    if (wallet == NULL)
    {
        wallet = malloc(sizeof(wallet));
        wallet->money = .0;
        wallet->stkOwn = 0;
        wallet->stock = NULL;
    }
    
    FILE* fp = fopen("./simulation/portefeuille", "r");
    if (fp)
    {
        // le fichier existe
        // la simulation existe deja
        // lire le fichier
        fscanf(fp, "%f\n%d\n", &money, &stkOwn);
        
        wallet->money = money;
        wallet->stkOwn = stkOwn;
        if (stkOwn == 0)
            return 1;
        
        wallet->stock = malloc(sizeof(Stock) * stkOwn);
        
        int i = 0;
        while((fscanf(fp, "%d;%f;%d\n", &(wallet->stock[i].stockId), &(wallet->stock[i].price), &(wallet->stock[i].nbr)) != EOF)
              && i < stkOwn)
        {
            i++;
        }
        fclose(fp);
        
        return 0;
    }
    else
    {
        // le fichier n'existe pas
        // proposer le debut d'une simulation
        // creation du fichier
        
        // demande a l'utilisateur les parametres initiaux du portefeuille
        
        return 1;
    }
    
}

void Initwallet(Wallet *wallet, float money)
{
    FILE* fp;
    fp = fopen("./simulation/portefeuille", "a");
    
    wallet = calloc(1, sizeof(struct wallet));
    wallet->money = money;
    wallet->stkOwn = 0;
    wallet->stock = NULL;
    
    char *string;
    asprintf(&string, "%f\n%d\n", money, 0);
    fputs(string, fp);
    free(string);
}

void Achat(Wallet *wallet, Stock stock, int nbrStock)
{
    if (wallet != NULL)
    {
        if (stock->last * nbrStock <= wallet->money)
        {
            
            
        }
        
    }
}

void Vente()
{
    
    
    
}