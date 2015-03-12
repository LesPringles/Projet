//
//  parsing.c
//  trading
//
//  Created by Charles on 07/03/15.
//  Copyright (c) 2015 Charles. All rights reserved.
//

#include "parsing.h"

pthread_t InitParsing(TabStock *tabStock, char *indice, int time)
{
    FILE* fp = fopen("./resources/URL", "r");
    if (fp == NULL)
    {
        printf("Fichier URL manquant\n");
        exit(EXIT_FAILURE);
        return NULL;
    }
    else
    {
        long f_size;
        char *URLs =NULL;
        char *ajaxURL = malloc(sizeof(char) * 100); // URL utilisé par le pThread plus tard, la portee doit etre plus grande que cette fonction
        char nameIdURL[100];
        char *ptr = NULL;
        int nbStock = 0;
        
        fseek(fp, 0, SEEK_END);
        f_size = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        URLs = malloc(sizeof(char) * f_size);
        fread(URLs, 1, f_size, fp);
        char searchIndice[10];
        
        do
        {
            ptr = strstr(URLs, "Indice = ");
            ptr += 9;
            sscanf(ptr, "%10[0-9A-Z]\n%d", searchIndice, &nbStock);

        } while (strcmp(searchIndice, indice) != 0);
        
        tabStock->size = (size_t)nbStock;
        tabStock->tab = calloc(tabStock->size, sizeof(struct stock) * tabStock->size);
        
        ptr = strstr(ptr, "URL Ajax = ");
        sscanf(ptr, "URL Ajax = %s[ˆ\n]\n", ajaxURL);
        ptr = strstr(ptr, "URL nameID = ");
        sscanf(ptr, "URL nameID = %s[ˆ\n]\n", nameIdURL);
        
        struct args_pthread *args = malloc(sizeof(struct args_pthread));
        args->URL = ajaxURL;
        args->tabStock = tabStock;
        args->time = time;
        
        Parsing(tabStock, ajaxURL);
        NameID(tabStock, nameIdURL);
        
        pthread_t thPars = 0;
        pthread_create(&thPars, NULL, pThreadParsing, (void*)args);
        
        fclose(fp);
        
        return thPars;
    }
}

void *pThreadParsing(void *_args)
{
    struct args_pthread *args = (struct args_pthread *)_args;
    while (1)
    {
        sleep(args->time);
        Parsing(args->tabStock, args->URL);
        printf("Update !\n");
    }
    
    return NULL;
}

void NameID(TabStock *tabStock, char *URL)
{
    char *sourceHTML = NULL;
    while (sourceHTML == NULL)
    {
        sourceHTML = LectureWeb(URL);
        if (sourceHTML)
            IdentificationID(sourceHTML, tabStock);
        else
            sleep(5);
    }
    free(sourceHTML);
}

void Parsing(TabStock *tabStock, char *URL)
{
    char *source = NULL;
    while (source == NULL)
    {
        source = LectureWeb(URL);
        if (source)
            ParseAjax(source, tabStock);
        else
            sleep(5);
    }
    free(source);
}

void ParseAjax(char *ajaxStr, TabStock *tabStock)
{
    char *ptr = ajaxStr + 65;
    int id = 0;
    float open, pct, last, high, ask, low, bid, prev;
    int volume = 0;
    char time[10];
    
    unsigned n = 0;
    while (n < tabStock->size) // le flux ajax contient aussi la valeur du CAC40
    {
        // parsing du flux ajax
        sscanf(ptr, "\"%d\" :{\"open\":\"%f\",\"time\":\"%[0-9:\\]\",\"pct\":\"%f\",\"last\":\"%f\",\"volume\":%d,\"high\":\"%f\",\"ask\":\"%f\",\"low\":\"%f\",\"bid\":\"%f\",\"prev\":\"%f\"},", &id, &open, time, &pct, &last, &volume, &high, &ask, &low, &bid, &prev);
        
        tabStock->tab[n].id = id;
        tabStock->tab[n].open = open;
        tabStock->tab[n].prev = prev;
        tabStock->tab[n].pct = pct;
        tabStock->tab[n].last = last;
        tabStock->tab[n].volume = volume;
        tabStock->tab[n].high = high;
        tabStock->tab[n].ask = ask;
        tabStock->tab[n].low = low;
        tabStock->tab[n].bid = bid;
        
        ptr = strstr(ptr, "},") + 2;
        // printf("%d \n%f\n\n", id, open);
        n++;
    }
}

void IdentificationID(char *htmlStr, TabStock *tabStock)
{
    int n = 0;
    char *ptr = strstr(htmlStr, "<h1>");
    char nameID[30];
    char label[6];
    int id = 0;
    Stock stock = NULL;
    
    while (n < tabStock->size - 1)
    {
        ptr = strstr(ptr, "title");
        ptr += 6; // on avance le pointeur de 'title=' pour tomber sur le premier nameID
        sscanf(ptr, "\"%30[^\"]", nameID); // parsing de "Carrefour" (exemple)
        ptr = strstr(ptr, "id="); // 'id=hmstock_'
        ptr += 12;
        sscanf(ptr, "%d\">%[A-Z]", &id, label);
        
        stock = getSTKbyID(id, tabStock);
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
    char path[100] = "./resources/";
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






