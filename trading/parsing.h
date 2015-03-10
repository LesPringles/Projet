//
//  parsing.h
//  trading
//
//  Created by Charles on 07/03/15.
//  Copyright (c) 2015 Charles. All rights reserved.
//

#ifndef __trading__parsing__
#define __trading__parsing__

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "action.h"
#include "reseau.h"
#define TAILLEPAGEWEB 1000000
#define STOCKNBR 41
#define STEP 1024

struct args_pthread
{
    TabStock *tabStock;
    char *URL;
    int time;
};

pthread_t InitParsing(TabStock *tabStock, char *indice);
void *pThreadParsing(void *tabStock);
void NameID(TabStock *tabStock, char *URL);
void Parsing(TabStock *tabStock, char *URL);
void ParseAjax(char *ajaxStr, TabStock *tabStock);
void IdentificationID(char *htmlStr, TabStock *tabStock);
size_t ParseHisto(char *labelStock, char *URLCVS, StockHisto **historique);

#endif /* defined(__trading__parsing__) */
