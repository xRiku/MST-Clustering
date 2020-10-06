#ifndef __POINT__
#define __POINT__
#include <stdlib.h>
#include <string.h>

typedef struct p{
    char* id;
    double* mValues;
    int m;
    struct p* set;
}Point;

Point *createPoint(char* id, int m, double* mValues);

void freePoint(Point *point);

void printPoint(Point *point);

#endif