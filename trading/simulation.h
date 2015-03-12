//
//  simulation.h
//  trading
//
//  Created by Charles on 08/03/15.
//  Copyright (c) 2015 Charles. All rights reserved.
//

#ifndef __trading__simulation__
#define __trading__simulation__

#include <stdio.h>
#include "action.h"
#define TAILLETABSTOCKSIM 10

typedef struct SimStock SimStock;
typedef struct wallet Wallet;

int ReadWallet(Wallet *wallet);
void Initwallet(Wallet *wallet, float money);
void Achat(Wallet *wallet, Stock stock, int nbrStock);
void Vente(Wallet *wallet, Stock stock, int nbrStock);
void SaveWallet(Wallet *wallet);

struct SimStock
{
    int stockId;
    float price; // le prix d'achat
    int nbr;
};

struct wallet
{
    float money;
    short unsigned stkOwn;
    SimStock* stock;
};

#endif /* defined(__trading__simulation__) */
