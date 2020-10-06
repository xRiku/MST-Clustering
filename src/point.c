#include "../include/point.h"
#include "../include/unionFind.h"
#include <stdio.h>

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
