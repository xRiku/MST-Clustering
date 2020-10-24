#include <math.h>
#include "../include/euclidean.h"

/**
 * @brief Calcula e retorna a distancia euclideana entre 2 vetores de doubles
 * 
 * @param coord1 Vetor 1
 * @param coord2 Vetor 2
 * @param m Dimensão dos vetores
 * @return double 
 */
double EuclideanDist(double *coord1, double *coord2, int m){
    double acc = 0;

    for (int i = 0; i < m; i++){
        double aux = (coord1[i] - coord2[i]);
        acc += aux * aux;
    }

    double result = sqrt(acc);

    return result;
}