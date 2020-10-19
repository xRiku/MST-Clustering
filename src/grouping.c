#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/grouping.h"
#include "../include/unionFind.h"

int comparePoint(const void *x, const void *y){
    Point *p1 = *((Point **) x);
    Point *p2 = *((Point **) y);

    char *p1SetId = getPointId(UFFind(p1));
    char *p2SetId = getPointId(UFFind(p2));

    int compIdSet = strcmp(p1SetId, p2SetId);
    if(compIdSet != 0){
        return compIdSet;
    }else{
        char *p1Id = getPointId(p1);
        char *p2Id = getPointId(p2);
        return strcmp(p1Id, p2Id); 
    }
}

int compareGroup(const void *x, const void *y){
    char **g1 = *((char ***) x);
    char **g2 = *((char ***) y);
    
    return strcmp(g1[0], g2[0]);
}

char ***newGroupMatrix(int k, int n){
    char ***groupMatrix = malloc(sizeof(char **) * k);

    for (int i = 0; i < k; i++){
        groupMatrix[i] = malloc(sizeof(char *) * n);
    }

    return groupMatrix;
}

void deleteGroupMatrix(char ***matrix, int k){
    for (int i = 0; i < k; i++){
        free(matrix[i]);
    }

    free(matrix);
}


void groupAndPrint(Point **list, int size, int k, FILE *output){
    qsort(list, size, (sizeof(list[0])), comparePoint);

    char ***groupMatrix = newGroupMatrix(k, size);

    Point *group = UFFind(list[0]);
    for (int i = 0, c = 0, groupCnt = 0; i < size; i++){
        if(group != UFFind(list[i])){
            groupMatrix[groupCnt][c] = "\0";
            groupCnt++;
            c = 0;
            group = UFFind(list[i]);
        }
        groupMatrix[groupCnt][c] = getPointId(list[i]);
        c++;

        if(i == (size-1)){
            groupMatrix[groupCnt][c] = "\0";
        }
    }

    for (int i = 0; i < k; i++){
        for (int j = 0; j < size; j++){
            if (strcmp(groupMatrix[i][j], "\0") == 0){
                break;
            }
            printf("%s ", groupMatrix[i][j]);
        }
        printf("\n");
    }

    deleteGroupMatrix(groupMatrix, k);
    
}