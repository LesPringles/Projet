//
//  reseau.h
//  trading
//
//  Created by Charles on 07/03/15.
//  Copyright (c) 2015 Charles. All rights reserved.
//

#ifndef __trading__reseau__
#define __trading__reseau__

#include <stdio.h>

struct BufferStruct
{
    char* buffer;
    size_t size;
};

static size_t WriteMemoryCallback(void* ptr, size_t size, size_t nmemb, void* data);

//Lecture de la page web
char* LectureWeb(char* AddURL);

#endif /* defined(__trading__reseau__) */
