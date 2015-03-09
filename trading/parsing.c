//
//  parsing.c
//  trading
//
//  Created by Charles on 07/03/15.
//  Copyright (c) 2015 Charles. All rights reserved.
//

#include "parsing.h"

void Init(Stock **tabStock)
{
    char *chaineHtml = malloc(sizeof(char) * TAILLEPAGEWEB);
    strcpy(chaineHtml, LectureWeb("http://www.lecho.be/bourses/euronext-paris/cac40"));
    IdentificationID(chaineHtml, tabStock, STOCKNBR);
    free(chaineHtml);
}

// fonciton de parsing du flux ajax. Prend en parametre la string du flux
void ParseAjax(char *ajaxStr, Stock **tabStock, size_t nbraction)
{
    char *ptr = ajaxStr + 65;
    int id = 0;
    float open, pct, last, high, ask, low, bid, prev;
    int volume = 0;
    char time[10];
    
    *tabStock = malloc(sizeof(Stock) * nbraction);
    
    unsigned n = 0;
    while (n < nbraction) // le flux ajax contient aussi la valeur du CAC40
    {
        // parsing du flux ajax
        sscanf(ptr, "\"%d\" :{\"open\":\"%f\",\"time\":\"%[0-9:\\]\",\"pct\":\"%f\",\"last\":\"%f\",\"volume\":%d,\"high\":\"%f\",\"ask\":\"%f\",\"low\":\"%f\",\"bid\":\"%f\",\"prev\":\"%f\"},", &id, &open, time, &pct, &last, &volume, &high, &ask, &low, &bid, &prev);
        
        
        (*tabStock)[n] = malloc(sizeof(struct stock));
        
        (*tabStock)[n]->id = id;
        (*tabStock)[n]->open = open;
        (*tabStock)[n]->pct = pct;
        (*tabStock)[n]->last = last;
        (*tabStock)[n]->volume = volume;
        (*tabStock)[n]->high = high;
        (*tabStock)[n]->ask = ask;
        (*tabStock)[n]->low = low;
        (*tabStock)[n]->bid = bid;
        (*tabStock)[n]->prev = prev;
        
        ptr = strstr(ptr, "},") + 2;
        // printf("%d \n%f\n\n", id, open);
        n++;
    }
    
}

// Identification du ID des actions pour avoir le nom correspondant
// Identification fait une seule fois a partir d'un parsing de la page HTML qui utilise le flux ajax
// Prend donc en parametre le code source de la page HTML sous forme de texte
void IdentificationID(char *htmlStr, Stock **tabStock, size_t stockNbr)
{
    int n = 0;
    char *ptr = strstr(htmlStr, "<h1>");
    char nameID[30];
    char label[6];
    int id = 0;
    Stock stock = NULL;
    
    while (n < stockNbr - 1)
    {
        ptr = strstr(ptr, "title");
        ptr += 6; // on avance le pointeur de 'title=' pour tomber sur le premier nameID
        sscanf(ptr, "\"%30[^\"]", nameID); // parsing de "Carrefour" (exemple)
        ptr = strstr(ptr, "id="); // 'id=hmstock_'
        ptr += 12;
        sscanf(ptr, "%d\">%[A-Z]", &id, label);
        
        stock = getSTKbyID(id, tabStock, stockNbr);
        strcpy(stock->name, nameID);
        strcpy(stock->label, label);
        
        // printf("%d\n%s\n\n", id, nameID);
        n++;
    }
    
}

// renvoie la taille du tableau
size_t ParseHisto(char *labelStock, char *URLCVS, StockHisto **historique)
{
    strcat(labelStock, ".txt");
    char path[100] = "/Users/user/Documents/Soutenance1/resources/";
    strcat(path, labelStock);
    FILE *fp = fopen(path,"r");
    char date[20];
    char indice[20];
    float open, high, low, close;
    int volume;
    int nbrday = 0;
    int i = 0;
    
    
    // si un cours a deja été récupéré
    // on lit le fichier
    if (fp != NULL)
    {
        fscanf(fp, "%d", &nbrday);
        if (nbrday == 0)
            return -1;
        *historique = malloc(sizeof(StockHisto) * nbrday);
        while((fscanf(fp, "%[^;];%[^;];%f;%f;%f;%f;%d\n",
                     indice, date, &open, &high, &low, &close, &volume) != EOF)
              && i < nbrday)
        {
            (*historique)[i] = malloc(sizeof(struct histo));
            (*historique)[i]->open = open;
            (*historique)[i]->high = high;
            (*historique)[i]->low = low;
            (*historique)[i]->close = close;
            i++;
        }
        fclose(fp);
        return nbrday;
    }
    else
    {
        // recuperer les cours depuis internet
        // si le fichier n'existe pas
        
        return 0;
    }

}






