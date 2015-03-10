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
#include <stdlib.h>

typedef struct stock *Stock;
typedef struct tabStock TabStock;
typedef struct histo *StockHisto;


struct tabStock
{
    size_t size;
    struct stock *tab;
};


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

struct histo
{
    float open, high, low, close;
    int volume;
};

void printS(Stock stock);
void printSTK(int stockId, TabStock *tabStock);
void printTabActions(TabStock *tabAction);
Stock getSTKbyID(int stockId, TabStock *tabStock);
Stock getStkByName(char* name, TabStock *tabStock);
void FreeTabStock(TabStock *tabStock);

#endif /* defined(__trading__action__) */
