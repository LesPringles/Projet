//
//  main.c
//  trading
//
//  Created by Charles on 07/03/15.
//  Copyright (c) 2015 Charles. All rights reserved.
//

#include "parsing.h"
#include "interface.h"
#define TAILLEPAGEWEB 1000000
#define STOCKNBR 41

int main(int argc, char *argv[])
{
    Stock *tabStock = NULL;
    InitParsing(&tabStock); // fonction qui fait le cafe
    
    printTabActions(&tabStock, STOCKNBR);
    
    pthread_t thPars = 0;
    pthread_create(&thPars, NULL, pThreadParsing, &tabStock);
    
    StockHisto* historique;
    ParseHisto((getStkByName("BNP Paribas", &tabStock, STOCKNBR))->label, NULL, &historique);
    
    interface(argc, argv);
    // cette fonction est bloquante, les lignes de codes après sont executées apres la fermeture de l'interface
    
    pthread_cancel(thPars);
    
    return EXIT_SUCCESS;
}

