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
#include <string.h>

typedef struct stock *Stock;
struct stock
{
    int id;
    char name[30]; // nombre de caractere du nom de l'action
    char label[6];
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

typedef struct histo *StockHisto;
struct histo
{
    float open, high, low, close;
    int volume;
};

void printS(Stock stock);
void printSTK(int stockId, Stock **tabStock, size_t stkNbr);
void printTabActions(Stock **tabAction, size_t nbrAction);
Stock getSTKbyID(int stockId, Stock **tabStock, size_t stkNbr);
Stock getStkByName(char* name, Stock **tabStock, size_t stkNbr);

#endif /* defined(__trading__action__) */
