#include "../include/point.h"
#include "../include/unionFind.h"
#include <stdio.h>
#include <string.h>

struct p{
    char* id;
    double* mValues;
    int m;
    Point *set;
};

Point *createPoint(char* id, int m, double* mValues){
    Point *point = malloc(sizeof(Point));
    point->m = m;
    point->id = malloc((1 + strlen(id)) * sizeof(char));
    strcpy(point->id, id);
    point->mValues = mValues;
    point->set = point;
    return point;
}

void freePoint(Point *point){
    free(point->id);
    free(point->mValues);
    free(point);
}

void printPoint(Point *point){
    printf("Id: %s\n", point->id);
    for (int i = 0; i < point->m; i++)
    {
        printf("%lf ", point->mValues[i]);
    }
    printf("Set: %p", UFFind(point));
    printf("\n");
}


double *getPointCoordinates(Point *point) {
    return point->mValues;
}

int getPointDimension(Point *point) {
    return point->m;
}

char *getPointId(Point *point) {
    return point->id;
}

Point *getPointSet(Point *point) {
    return point->set;
}

void setPointSet(Point *point, Point *set){
    point->set = set;
}


int comparePointId(const void *p1, const void *p2){
    char *val1 = ((Point*)p1)->id;
    char *val2 = ((Point*)p2)->id;
    
    return strcmp(val1, val2);
    
}

void printPointVector(Point **x, int size){
    for (int i = 0; i < size; i++)
    {
        printPoint(x[i]);
    }
}

void deletePointVector(Point **x, int size){
    for (int i = 0; i < size; i++)
    {
        freePoint(x[i]);
    }
    free(x);
}