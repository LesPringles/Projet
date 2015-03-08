//
//  action.h
//  trading
//
//  Created by Charles on 08/03/15.
//  Copyright (c) 2015 Charles. All rights reserved.
//

#ifndef __trading__action__
#define __trading__action__

#include <stdio.h>

typedef struct stock *Stock;
struct stock
{
    int id;
    char name[20]; // nombre de caractere du nom de l'action
    float open;
    float pct;
    float last;
    int volume;
    float high;
    float bid;
    float ask;
    float low;
    float prev;
};

void printS(Stock stock);
void printSTK(int stockId, Stock **tabStock, size_t stkNbr);
void printTabActions(Stock **tabAction, size_t nbrAction);
Stock getSTKbyID(int stockId, Stock **tabStock, size_t stkNbr);

#endif /* defined(__trading__action__) */
