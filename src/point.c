#include "../include/point.h"
#include <stdio.h>

Point createPoint(char* id, int m, double* mValues){
    Point point;
    point.m = m;
    point.id = malloc((1 + strlen(id)) * sizeof(char));
    strcpy(point.id, id);
    point.mValues = malloc(m * sizeof(double));
    for(int i = 0; i < m; i++){
        point.mValues[i] = mValues[i];
    }
    return point;
}

void freePoint(Point point){
    free(point.id);
    free(point.mValues);
}

void printPoint(Point point){
    printf("Id: %s\n", point.id);
    for (int i = 0; i < point.m; i++)
    {
        printf("%lf ", point.mValues[i]);
    }
    printf("\n");
    
}
