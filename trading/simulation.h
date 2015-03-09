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
#include <stdlib.h>

typedef struct stock Stock;
struct stock
{
    int stockId;
    float price; // le prix d'achat
    int nbr;
};

typedef struct wallet wallet;
struct wallet
{
    float argent;
    short unsigned StkOwn;
    Stock* stock;
};

int ReadWallet(wallet *wallet);

#endif /* defined(__trading__simulation__) */
