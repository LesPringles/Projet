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

pthread_t InitParsing(TabStock *tabStock, char *indice, int time);

// fonction d'actualisation automatique via un pThread
// prend en argument une structure args_pthread
// qui contient l'adresse du tableau à rafraichir,
// l'URL à parser et le temps d'actualisation en seconde

void *pThreadParsing(void *tabStock);
void NameID(TabStock *tabStock, char *URL);
void Parsing(TabStock *tabStock, char *URL);

// fonciton de parsing du flux ajax. Prend en parametre la string du flux
void ParseAjax(char *ajaxStr, TabStock *tabStock);

// Identification du ID des actions pour avoir le nom correspondant
// Identification fait une seule fois a partir d'un parsing de la page HTML qui utilise le flux ajax
// Prend donc en parametre le code source de la page HTML sous forme de texte
void IdentificationID(char *htmlStr, TabStock *tabStock);


size_t ParseHisto(char *labelStock, char *URLCVS, StockHisto **historique);

#endif /* defined(__trading__parsing__) */
