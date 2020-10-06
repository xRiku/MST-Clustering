#include "../include/kruskal.h"
#include "../include/point.h"
#include "../include/euclidean.h"
#include <stdio.h>
#include <stdlib.h>

distCell distBetweenPoints(Point *p1, Point *p2){
    distCell resultCell;
    double result = EuclideanDist(p1->mValues, p2->mValues, p1->m);
    resultCell.p1 = p1->id;
    resultCell.p2 = p2->id;
    resultCell.dist = result;
    return resultCell;
}

void printDistanceMatrix(distMatrix matrix, int N){
    for (int i = 0; i < (N-1); i++){
        for (int c = 0; c < (N-i-1); c++){
            printf("%lf ", matrix[i][c].dist);
        }
        printf("\n");
    }
}

/** 
 * Para N = 5, matriz será (em índices):
 * matriz[0] = 0 1 2 3
 * matriz[1] = 0 1 2
 * matriz[2] = 0 1
 * matriz[3] = 0
 * 
 * Em distancia entre pontos (AB = Distancia entre A e B):
 * matriz[0] = AB AC AD AE
 * matriz[1] = BC BD BE
 * matriz[2] = CD CE
 * matriz[3] = DE
**/
distMatrix newDistanceMatrix(int N){
    distMatrix matrix;

    // Aloca linhas da matriz
	matrix = (distMatrix )malloc(sizeof(distCell *) * (N-1));

    // Aloca colunas da matriz
	for(int size = (N-1), i = 0; size>=1, i<(N-1); size--, i++){
		printf("vetor %d tam %d\n", i, size);
		matrix[i] = (distCell *)malloc(sizeof(distCell) * size);
	}

    return matrix;
}

void freeDistanceMatrix(distMatrix matrix, int N){
    for (int i = 0; i < (N-1); i++){
        distCell *line = matrix[i];
        free(line);
    }
    free(matrix);
}


distMatrix DistanceMatrix(List *pointList){
	int N = pointList->length;
	distMatrix matrix = newDistanceMatrix(N);

    Item *p1Cell = NULL;
    for (int i = 0; i < (N-1); i++){
        if(p1Cell == NULL){
            p1Cell = pointList->head;
        }else{
            p1Cell = p1Cell->next;
        }
        Point *p1 = p1Cell->element;

        Item *p2Cell = NULL;
        for (int c = 0; c < (N-i-1); c++){
            if(p2Cell == NULL){
                p2Cell = p1Cell->next;
            }else{
                p2Cell = p2Cell->next;
            }
            Point *p2 = p2Cell->element;

            matrix[i][c] = distBetweenPoints(p1, p2);
        }
    }

    return matrix;
}
