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
    char chaine[50000];  //À changer selon la taille du flux ajax besoin
    strcpy(chaine, LectureWeb("http://1.ajax.lecho.be/rtq/?reqtype=simple&quotes=360015511&lightquotes=&group=g30_q_p")); // adresse html du flux ajax du CAC40
    
    Stock *tabStock;
    
    ParseAjax(chaine, &tabStock, STOCKNBR);
    Init(&tabStock);
    
    printTabActions(&tabStock, STOCKNBR);
    
    StockHisto* historique;
    ParseHisto((getStkByName("BNP Paribas", &tabStock, STOCKNBR))->label, NULL, &historique);
    
    // interface(argc, argv);
    
    return 0;
}

