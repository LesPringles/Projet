//
//  main.c
//  trading
//
//  Created by Charles on 07/03/15.
//  Copyright (c) 2015 Charles. All rights reserved.
//

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "reseau.h"
#include "parsing.h"
#define TAILLEPAGEWEB 1000000
#define STOCKNBR 41

void Init(Stock **tabStock)
{
    char *chaineHtml = malloc(sizeof(char) * TAILLEPAGEWEB);
    strcpy(chaineHtml, LectureWeb("http://www.lecho.be/bourses/euronext-paris/cac40"));
    IdentificationID(chaineHtml, tabStock, STOCKNBR);
    free(chaineHtml);
}

int main(const int argc, const char *argv[])
{
    char chaine[50000];  //À changer selon la taille du flux ajax besoin
    strcpy(chaine, LectureWeb("http://1.ajax.lecho.be/rtq/?reqtype=simple&quotes=360015511&lightquotes=&group=g30_q_p")); // adresse html du flux ajax du CAC40
    
    Stock *tabStock;
    
    ParseAjax(chaine, &tabStock, STOCKNBR);
    Init(&tabStock);
    
    printTabActions(&tabStock, STOCKNBR);
    
    
    return 0;
}

