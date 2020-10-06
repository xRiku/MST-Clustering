#ifndef _KRUSKAL_
#define _KRUSKAL_
#include "point.h"
#include "linkedlist.h"

typedef struct distCell{
	char *p1;
	char *p2;
	double dist;
} distCell;

typedef distCell** distMatrix;


distCell distBetweenPoints(Point *p1, Point *p2);

void printDistanceMatrix(distMatrix matrix, int N);

distMatrix newDistanceMatrix(int N);

void freeDistanceMatrix(distMatrix matrix, int N);

distMatrix DistanceMatrix(List *pointList);

#endif