//
//  parsing.h
//  trading
//
//  Created by Charles on 07/03/15.
//  Copyright (c) 2015 Charles. All rights reserved.
//

#ifndef __trading__parsing__
#define __trading__parsing__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "action.h"
#define STEP 1024

void ParseAjax(char *ajaxStr, Stock* tabStock[], size_t nbraction);
void IdentificationID(char *htmlStr, Stock **tabStock, size_t nbraction);
size_t ParseHisto(char *labelStock, char *URLCVS, StockHisto **historique);

#endif /* defined(__trading__parsing__) */
