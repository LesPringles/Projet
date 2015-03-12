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
    if (fp != NULL)
    {
        // le fichier existe
        // la simulation existe deja
        // lire le fichier
        fscanf(fp, "%f\n%d\n", &money, &stkOwn);
        
        wallet->money = money;
        wallet->stkOwn = stkOwn;
        if (stkOwn == 0)
            return 1; // pas d'action
        
        wallet->stock = malloc(sizeof(Stock) * TAILLETABSTOCKSIM);
        
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
    
    if (fp != NULL)
    {
        wallet = calloc(1, sizeof(struct wallet));
        wallet->money = money;
        
        char *string;
        asprintf(&string, "%f\n%d\n", money, 0);
        fputs(string, fp);
        free(string);
    }
}

void Achat(Wallet *wallet, Stock stock, int nbrStock)
{
    if (wallet != NULL)
    {
        if (stock->last * nbrStock <= wallet->money)
        {
            if (wallet->stock == NULL)
            {
                // aucune action dans le portefeuille
                wallet->stock = malloc(sizeof(struct SimStock));
                wallet->stock->stockId = stock->id;
                wallet->stock->price = stock->last;
                wallet->stock->nbr = nbrStock;
                wallet->stkOwn = 1;
            }
            else
            {
                // rechercher si l'action est deja posseder
                int i = 0;
                while ((i < wallet->stkOwn) && (wallet->stock[i].stockId != stock->id))
                {
                    i++;
                }
                if (wallet->stock[i].stockId == stock->id)
                {
                    // l'action est deja dans le portefeuille
                    // recalcule du prix de revient
                    float newNbStock = wallet->stock[i].nbr + nbrStock;
                    wallet->stock[i].price = (wallet->stock[i].price * wallet->stock[i].nbr + stock->last * nbrStock) / newNbStock;
                    wallet->stock[i].nbr = newNbStock;
                    
                }
                else
                {
                    wallet->stkOwn++;
                    if (wallet->stkOwn >= TAILLETABSTOCKSIM) // grosse flemme
                    {
                        wallet->stock[i+1].stockId = stock->id;
                        wallet->stock[i+1].price = stock->last;
                        wallet->stock[i+1].nbr = nbrStock;
                    }
                    else
                    {
                        printf("Tableau simulation trop petit");
                    }
                }
            }
            wallet->money -= stock->last * nbrStock;
        }
        else
        {
            // pas assez d'argent
            
        }
        
    }
}

void Vente(Wallet *wallet, Stock stock, int nbrStock)
{
    if (wallet != NULL)
    {
        if (wallet->stock != NULL)
        {
            // Recherche de l'action
            int i;
            while ((i < wallet->stkOwn) && (wallet->stock[i].stockId != stock->id))
            {
                i++;
            }
            
            // Si le nombre d'action vendue est supérieur ou égal au nombre d'action posseder
            if (wallet->stock[i].nbr >= nbrStock)
            {
                wallet->stock[i].nbr -= nbrStock;
                wallet->money += nbrStock * stock->last;
            }
            else
            {
                printf("Pas assez d'action");
            }
            
        }
        else
        {
            printf("Tableau d'action non initialiser");
        }
        
    }
    else
    {
        printf("Erreur portefeuille");
    }
    
}

void SaveWallet(Wallet *wallet)
{
    FILE* fp;
    fp = fopen("./simulation/portefeuille", "w");
    
    if (fp != NULL)
    {
        char *string;
        asprintf(&string, "%f\n%d\n", wallet->money, wallet->stkOwn);
        fputs(string, fp);
        int i = 0;
        while (i < wallet->stkOwn)
        {
            sprintf(string, "%d;%f;%d\n", wallet->stock[i].stockId, wallet->stock[i].price, wallet->stock[i].nbr);
            fputs(string, fp);
        }
        free(string);
    }
}