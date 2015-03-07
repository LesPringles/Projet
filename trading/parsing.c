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
#define NBRACTION 41

void ParseAjax(char *ajaxStr)
{
    char str2[50000];
    char str3[50000];
    int id = 0;
    float open, pct, last, high, ask, low, bid, prev;
    int volume = 0;
    char time[8];
    sscanf(&ajaxStr[65], "%50000s", str2);
    unsigned n = 0;
    while (n < NBRACTION)
    {
        sscanf(str2, "\"%d\" :{\"open\":\"%f\",\"time\":\"%5s\",\"pct\":\"%f\",\"last\":\"%f\",\"volume\":%d,\"high\":\"%f\",\"ask\":\"%f\",\"low\":\"%f\",\"bid\":\"%f\",\"prev\":\"%f\"}, %s", &id, &open, time, &pct, &last, &volume, &high, &ask, &low, &bid, &prev, str3);
        strcpy(str2, str3);
        
        printf("%d \n%f\n", id, open);
        printf("\n");
        n++;
    }
    
}


void Id(char *htmlStr)
{
    int n = 0;
    char *ptr = strstr(htmlStr, "<h1>");
    while (n < NBRACTION)
    {
        
        
    }
    
    
    
    
}