//
//  reseau.c
//  trading
//
//  Created by Charles on 07/03/15.
//  Copyright (c) 2015 Charles. All rights reserved.
//

#include "reseau.h"
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <curl/easy.h>


//Met le contenu de la page web dans la struct
static size_t WriteMemoryCallback(void* ptr, size_t size, size_t nmemb, void* data)
{
    size_t realsize = size * nmemb;
    struct BufferStruct* mem = (struct BufferStruct*) data;
    mem->buffer = (char*)realloc(mem->buffer, mem->size + realsize + 1);
    
    if ( mem->buffer )
    {
        memcpy(&(mem->buffer[mem->size]), ptr, realsize );
        mem->size += realsize;
        mem->buffer[ mem->size ] = 0;
    }
    
    return realsize;
}

char* LectureWeb(char* AddURL)
{
    curl_global_init(CURL_GLOBAL_ALL);
    
    CURL *myHandle;
    CURLcode result;
    struct BufferStruct LectureLC;
    LectureLC.buffer = NULL;
    LectureLC.size = 0;
    
    myHandle = curl_easy_init();
    curl_easy_setopt(myHandle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(myHandle, CURLOPT_WRITEDATA, (void*)&LectureLC);
    curl_easy_setopt(myHandle, CURLOPT_URL, AddURL);
    result = curl_easy_perform(myHandle);  //voir la doc pour une gestion minimal des erreurs
    curl_easy_cleanup(myHandle);
    
    if(result!=0)
        LectureLC.size=1;
    
    char *chaine = malloc(sizeof(char) * LectureLC.size);
    strcpy(chaine, LectureLC.buffer);
    strcat(chaine,"\0");
    
    if(LectureLC.buffer)
        free(LectureLC.buffer);
    
    return chaine;
}