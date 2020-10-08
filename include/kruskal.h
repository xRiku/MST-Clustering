#ifndef _KRUSKAL_
#define _KRUSKAL_
#include "point.h"
#include "linkedlist.h"

typedef struct distCell distCell;

distCell distBetweenPoints(Point *p1, Point *p2);

int calcDistN(int N);

void printDistCell(distCell *x);

void printDistanceVector(distCell *x, int N);

distCell *distanceVector(List *pointList);

void sortDists(distCell *list, int size);

void kruskalK(distCell *distVect, int size, int N, int k);

Point *getPoint1(distCell *distVect);

Point *getPoint2(distCell *distVect);

double getDistance(distCell *distVect);

#endif