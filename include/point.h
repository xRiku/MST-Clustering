#ifndef __POINT__
#define __POINT__
#include <stdlib.h>
#include <string.h>

typedef struct p{
    char* name;
    double* mValues;
    int m;
}Point;

Point createPoint(char* name, int m, double* mValues);

void freePoint(Point point);

#endif