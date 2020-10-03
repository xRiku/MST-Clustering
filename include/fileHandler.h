#ifndef __FILE_READ__
#define __FILE_READ__

#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>

List* fileToPoint(FILE *);

char *readNewLine(FILE* );

int countPointDimension(FILE *);

#endif