#ifndef _KRUSKAL_
#define _KRUSKAL_
#include "point.h"
#include "linkedlist.h"

typedef struct distCell{
	char *p1;
	char *p2;
	double dist;
} distCell;

distCell distBetweenPoints(Point *p1, Point *p2);

int calcDistN(int N);

void printDistCell(distCell *x);

void printDistanceVector(distCell *x, int N);

distCell *distanceVector(List *pointList);

#endif