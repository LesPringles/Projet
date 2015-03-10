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

void printSTK(int stockId, TabStock *tabStock)
{
    Stock stock = getSTKbyID(stockId, tabStock);
    printS(stock);
}

void printTabActions(TabStock *tabStock)
{
    for (int i = 0; i < tabStock->size ; i++)
    {
        printS(&(tabStock->tab[i]));
    }
}


Stock getSTKbyID(int stockId, TabStock *tabStock)
{
    unsigned i = 0;
    while (i < tabStock->size && tabStock->tab[i].id != stockId)
    {
        i++;
    }
    
    if (i >= tabStock->size)
    {
        printf("Stock not found\n");
        return NULL;
    }
    else
    {
        return &(tabStock->tab[i]);
    }
}

Stock getStkByName(char* name, TabStock *tabStock)
{
    unsigned i = 0;
    while (i < tabStock->size && (strcmp(name, tabStock->tab[i].name) != 0))
    {
        i++;
    }
    
    if (i >= tabStock->size)
    {
        printf("Stock not found");
        return NULL;
    }
    else
    {
        return &(tabStock->tab[i]);
    }
}

void FreeTabStock(TabStock *tabStock)
{
    if (tabStock->tab != NULL)
    {
        free(tabStock->tab);
    }
}





