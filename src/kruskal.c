#include "../include/kruskal.h"
#include "../include/point.h"
#include "../include/euclidean.h"
#include "../include/unionFind.h"
#include <stdio.h>
#include <stdlib.h>

distCell distBetweenPoints(Point *p1, Point *p2){
    distCell resultCell;
    double result = EuclideanDist(p1->mValues, p2->mValues, p1->m);
    resultCell.p1 = p1;
    resultCell.p2 = p2;
    resultCell.dist = result;
    return resultCell;
}

int calcDistN(int N){
    return ((N*(N-1))/2);
}

void printDistCell(distCell *x){
    printf("P1: %s Set: %s\nP2: %s Set: %s\n", x->p1->id, UFFind(x->p1)->id, x->p2->id, UFFind(x->p2)->id);
    printf("Dist: %lf\n", x->dist);
}

void printDistanceVector(distCell *x, int N){
    int size = calcDistN(N);
    for (int i = 0; i < size; i++){
        printDistCell(&(x[i]));
    }
}

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

void sortDists(distCell *list, int N){
    int size = calcDistN(N);

    qsort((void *)list, size, (sizeof(list[0])), distComparator);
}


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
    }

    sortDists(vector, N);

    return vector;
}

void kruskalK(distCell *distVect, int N, int k){
    int qtdComps = N;
    for(int i = 0; qtdComps == k && i < N; i++){
        if(UFFind(distVect[i].p1) != UFFind(distVect[i].p2)){
            UFUnion(distVect[i].p1, distVect[i].p2);
            qtdComps--;
        }
    }
}