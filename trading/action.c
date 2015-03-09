//
//  action.c
//  trading
//
//  Created by Charles on 08/03/15.
//  Copyright (c) 2015 Charles. All rights reserved.
//

#include "action.h"

void printS(Stock stock)
{
    printf("%s - %s\nID : %d\nopen : %f\n%f%%\nlast : %f\nVolume : %d\nHigh : %f\nBid : %f\nAsk : %f\nLow : %f\nPrev : %f\n\n",
           stock->name, stock->label, stock->id, stock->open, stock->pct, stock->last, stock->volume, stock->high, stock->bid, stock->ask, stock->low, stock->prev);
}

void printSTK(int stockId, Stock **tabStock, size_t stkNbr)
{
    Stock stock = getSTKbyID(stockId, tabStock, stkNbr);
    printS(stock);
}

void printTabActions(Stock **tabAction, size_t nbrAction)
{
    for (int i = 0; i < nbrAction; i++)
    {
        printS((*tabAction)[i]);
    }
}


Stock getSTKbyID(int stockId, Stock **tabStock, size_t stkNbr)
{
    unsigned i = 0;
    while (i < stkNbr && (*tabStock)[i]->id != stockId)
    {
        i++;
    }
    
    if ((*tabStock)[i] == NULL || (*tabStock)[i]->id != stockId)
    {
        printf("Stock not found");
        return NULL;
    }
    else
    {
        return ((*tabStock)[i]);
    }
}

Stock getStkByName(char* name, Stock **tabStock, size_t stkNbr)
{
    unsigned i = 0;
    while (i < stkNbr && (strcmp(name, (*tabStock)[i]->name) != 0))
    {
        i++;
    }
    
    if ((*tabStock)[i] == NULL || (strcmp(name, (*tabStock)[i]->name) != 0))
    {
        printf("Stock not found");
        return NULL;
    }
    else
    {
        return ((*tabStock)[i]);
    }
}

void FreeTabStock(Stock **tabStock, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        free((*tabStock)[i]);
    }
    free((*tabStock));
}





