#ifndef __FILE_READ__
#define __FILE_READ__
#include "point.h"
#include <stdlib.h>
#include <stdio.h>

Point* fileToPoint(FILE *);

char *readNewLine(FILE* );

int countPointDimension(FILE *);

#endif