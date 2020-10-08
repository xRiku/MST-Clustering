#ifndef __POINT__
#define __POINT__
#include <stdlib.h>
#include <string.h>

typedef struct p Point;

Point *createPoint(char* id, int m, double* mValues);

void freePoint(Point *point);

void printPoint(Point *point);

double *getPointCoordinates(Point *point);

int getPointDimension(Point *point);

char *getPointId(Point *point);

Point *getPointSet(Point *point);

void setPointSet(Point *point, Point *set);

#endif