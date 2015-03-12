//
//  main.c
//  trading
//
//  Created by Charles on 07/03/15.
//  Copyright (c) 2015 Charles. All rights reserved.
//

#include "parsing.h"
#include "interface.h"
#include "simulation.h"
#define TAILLEPAGEWEB 1000000
#define STOCKNBR 41

int main(int argc, char *argv[])
{
    TabStock tabStock;
    pthread_t updateCAC40 = InitParsing(&tabStock, "CAC40", 1); // fonction qui fait le cafe
    
    Wallet wallet;
    if (ReadWallet(&wallet))
        Initwallet(&wallet, 100000);
    
    Achat(&wallet, getStkByName("Technip", &tabStock), 200);
    Achat(&wallet, getStkByName("Sanofi", &tabStock), 300);
    Achat(&wallet, getStkByName("Capgemini", &tabStock), 300);
    SaveWallet(&wallet);
    
    interface(argc, argv, &tabStock);
    // cette fonction est bloquante, les lignes de codes après sont executées apres la fermeture de l'interface
    
    pthread_cancel(updateCAC40);
    FreeTabStock(&tabStock);
    
    return EXIT_SUCCESS;
}

