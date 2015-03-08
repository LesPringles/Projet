//
//  parsing.c
//  trading
//
//  Created by Charles on 07/03/15.
//  Copyright (c) 2015 Charles. All rights reserved.
//

#include "parsing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STEP 1024
#define NBRACTION 40

// fonciton de parsing du flux ajax. Prend en parametre la string du flux
void ParseAjax(char *ajaxStr)
{
    char *ptr = ajaxStr + 65;
    int id = 0;
    float open, pct, last, high, ask, low, bid, prev;
    int volume = 0;
    char time[8];
    unsigned n = 0;
    while (n < NBRACTION + 1) // le flux ajax contient aussi la valeur du CAC40
    {
        // parsing du flux ajax
        sscanf(ptr, "\"%d\" :{\"open\":\"%f\",\"time\":\"%5s\",\"pct\":\"%f\",\"last\":\"%f\",\"volume\":%d,\"high\":\"%f\",\"ask\":\"%f\",\"low\":\"%f\",\"bid\":\"%f\",\"prev\":\"%f\"},", &id, &open, time, &pct, &last, &volume, &high, &ask, &low, &bid, &prev);
        ptr = strstr(ptr, "},") + 2;
        
        printf("%d \n%f\n\n", id, open);
        n++;
    }
    
}

// Identification du ID des actions pour avoir le nom correspondant
// Identification fait une seule fois a partir d'un parsing de la page HTML qui utilise le flux ajax
// Prend donc en parametre le code source de la page HTML sous forme de texte
void IdentificationID(char *htmlStr)
{
    int n = 0;
    char *ptr = strstr(htmlStr, "<h1>");
    char nameID[40];
    int id = 0;
    while (n < NBRACTION)
    {
        ptr = strstr(ptr, "title");
        ptr += 6; // on avance le pointeur de 'title=' pour tomber sur le premier nameID
        sscanf(ptr, "\"%40[^\"]", nameID); // parsing de "Carrefour" (exemple)
        ptr = strstr(ptr, "id=") + 12;   // 'id=hmstock_'
        sscanf(ptr, "%d", &id);
        printf("%d\n%s\n\n", id, nameID);
        n++;
    }
    
}