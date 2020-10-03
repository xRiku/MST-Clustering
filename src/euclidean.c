#include "../include/euclidean.h"
#include "math.h"

double EuclideanDist(double *coord1, double *coord2, int m){
    double acc = 0;

    for (int i = 0; i < m; i++){
        double aux = (coord1[i] - coord2[i]);
        acc += aux * aux;
    }

    double result = sqrt(acc);

    return result;
}