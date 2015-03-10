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
    TabStock tabStock;
    pthread_t pth = InitParsing(&tabStock, "CAC40"); // fonction qui fait le cafe
    
    printTabActions(&tabStock);
    
    StockHisto* historique;
    ParseHisto((getStkByName("BNP Paribas", &tabStock))->label, NULL, &historique);
    
    interface(argc, argv);
    // cette fonction est bloquante, les lignes de codes après sont executées apres la fermeture de l'interface
    
    pthread_cancel(pth);
    FreeTabStock(&tabStock);
    
    return EXIT_SUCCESS;
}

