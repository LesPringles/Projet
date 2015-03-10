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

typedef struct SimStock SimStock;
struct SimStock
{
    int stockId;
    float price; // le prix d'achat
    int nbr;
};

typedef struct wallet Wallet;
struct wallet
{
    float money;
    short unsigned stkOwn;
    SimStock* stock;
};

int ReadWallet(Wallet *wallet);

#endif /* defined(__trading__simulation__) */
