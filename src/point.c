#include "../include/point.h"

Point createPoint(char* name, int m, double* mValues){
    Point point;
    point.m = m;
    point.name = malloc((1 + strlen(name)) * sizeof(char));
    strcpy(point.name, name);
    point.mValues = malloc(m * sizeof(double));
    for(int i = 0; i < m; i++){
        point.mValues[i] = mValues[i];
    }
    return point;
}

void freePoint(Point point){
    free(point.name);
    free(point.mValues);
}