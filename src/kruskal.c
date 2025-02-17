#include "../include/kruskal.h"
#include "../include/point.h"
#include "../include/euclidean.h"
#include "../include/unionFind.h"
#include <stdio.h>
#include <stdlib.h>

struct distCell{
	Point *p1;
	Point *p2;
	double dist;
};

/**
 * @brief Calcula a distancia euclideana entre 2 pontos.
 * Retorna uma struct com a referencia de cada ponto e o valor da distancia.
 * 
 * @param p1 
 * @param p2 
 * @return distCell 
 */
distCell distBetweenPoints(Point *p1, Point *p2){
    distCell resultCell;
    double result = EuclideanDist(getPointCoordinates(p1), getPointCoordinates(p2), getPointDimension(p1));
    resultCell.p1 = p1;
    resultCell.p2 = p2;
    resultCell.dist = result;
    return resultCell;
}

/**
 * @brief Calcula a quantidade de distancias a serem calculadas.
 * 
 * @param N Quantidade de pontos
 * @return int 
 */
int calcDistN(int N){
    return ((N*(N-1))/2);
}

/**
 * @brief Imprime na tela algumas informações de uma struct de distancia.
 * 
 * @param x 
 */
void printDistCell(distCell *x){
    // printf("P1: %s Set: %s\nP2: %s Set: %s\n", x->p1->id, UFFind(x->p1)->id, x->p2->id, UFFind(x->p2)->id);
    printf("P1: %s Set: %s\nP2: %s Set: %s\n", getPointId(x->p1), getPointId(UFFind(x->p1)), getPointId(x->p2), getPointId(UFFind(x->p2)));
    printf("Dist: %lf\n", x->dist);
}

/**
 * @brief Imprime na tela as structs de distancia de um vetor
 * 
 * @param x 
 * @param N 
 */
void printDistanceVector(distCell *x, int N){
    int size = calcDistN(N);
    for (int i = 0; i < size; i++){
        printDistCell(&(x[i]));
    }
}

/**
 * @brief Função de comparação pra ser usada no qsort().
 * Compara 2 structs de distancia baseado no valor da distancia.
 * 
 * @param d1 
 * @param d2 
 * @return int 
 */
int distComparator(const void *d1, const void *d2){
    double val1 = ((distCell*)d1)->dist;
    double val2 = ((distCell*)d2)->dist;
    
    if(val1 < val2){
        return -1;
    }else if(val1 == val2){
        return 0;
    }else{
        return 1;
    }
}

/**
 * @brief Ordena um vetor de distancias
 * 
 * @param list 
 * @param size 
 */
void sortDists(distCell *list, int size){
    qsort((void *)list, size, (sizeof(list[0])), distComparator);
}


/**
 * @brief Monta um vetor de distancias com as distancias entre todos os pontos da lista.
 * 
 * @param pointList Lista encadeada de pontos.
 * @return distCell* 
 */
distCell *distanceVector(List *pointList){
    int N = pointList->length;
	distCell *vector = (distCell *)malloc(sizeof(distCell) * calcDistN(N));

    Item *p1Cell = NULL;
    /**
     * i = indice pro ponto 1
     * j = indice pro vetor de distancia
     * c = indice pro ponto 2
    **/
    for (int i = 0, j = 0; i < (N-1); i++){
        if(p1Cell == NULL){
            p1Cell = pointList->head;
        }else{
            p1Cell = p1Cell->next;
        }
        Point *p1 = p1Cell->element;

        Item *p2Cell = NULL;
        for (int c = 0; c < (N-i-1); c++, j++){
            if(p2Cell == NULL){
                p2Cell = p1Cell->next;
            }else{
                p2Cell = p2Cell->next;
            }
            Point *p2 = p2Cell->element;

            vector[j] = distBetweenPoints(p1, p2);
        }
        freePointCoord(p1);
        if(i == (N-2)){
            freePointCoord(p1Cell->next->element);
        }

    }

    return vector;
}

/**
 * @brief Algoritmo de Kruskal modificado para encontrar uma floresta com k árvores geradoras
 * 
 * @param distVect Vetor de distancias
 * @param size Tamanho do vetor de distancias
 * @param N Quantidade de pontos
 * @param k Quantidade de árvores/componentes conexas a serem obtidas
 */
void kruskalK(distCell *distVect, int size, int N, int k){
    int qtdComps = N;
    for(int i = 0; qtdComps != k && i < size; i++){
        if(UFFind(distVect[i].p1) != UFFind(distVect[i].p2)){
            UFUnion(distVect[i].p1, distVect[i].p2);
            qtdComps--;
        }
    }
}

/**
 * @brief Retorna o primeiro ponto
 * 
 * @param x Struct de distancia
 * @return Point* 
 */
Point *getPoint1(distCell x){
    return x.p1;
}

/**
 * @brief Retorna o segundo ponto
 * 
 * @param x Struct de distancia
 * @return Point* 
 */
Point *getPoint2(distCell x){
    return x.p2;
}

/**
 * @brief Retorna a distancia
 * 
 * @param x Struct de distancia
 * @return double 
 */
double getDistance(distCell x){
    return x.dist;
}