#ifndef __POINT__
#define __POINT__
#include <stdlib.h>
#include <string.h>

typedef struct p Point;

Point *createPoint(char* id, int m, double* mValues);

void freePoint(Point *point);

void freePointCoord(Point *point);

void printPoint(Point *point);

double *getPointCoordinates(Point *point);

int getPointDimension(Point *point);

char *getPointId(Point *point);

Point *getPointSet(Point *point);

int getTreeSize(Point *point);

void setTreeSize(Point *point, int size);

void setPointSet(Point *point, Point *set);

int comparePointId(const void *p1, const void *p2);

void deletePointVector(Point **x, int size);

void printPointVector(Point **x, int size);

#endif