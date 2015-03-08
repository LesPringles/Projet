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

int main(const int argc, char **argv)
{
    char chaine[50000];  //À changer selon vos besoin
    char *chaineHtml = malloc(sizeof(char) * TAILLEPAGEWEB);
    strcpy(chaine, LectureWeb("http://1.ajax.lecho.be/rtq/?reqtype=simple&quotes=360015511&lightquotes=&group=g30_q_p"));
    strcpy(chaineHtml, LectureWeb("http://www.lecho.be/bourses/euronext-paris/cac40"));
    
    ParseAjax(chaine);
    IdentificationID(chaineHtml);
    
    free(chaineHtml);
    
    return 0;
}

