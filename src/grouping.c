#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/grouping.h"
#include "../include/unionFind.h"

/**
 * @brief Função comparadora pra ser usada no qsort().
 * Compara dois pontos pelo identificador de suas componentes conexas.
 * Caso sejam iguais, compara pelos seus identificadores.
 * 
 * @param x 
 * @param y 
 * @return int 
 */
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

/**
 * @brief Função comparadora pra ser usada no qsort().
 * Compara 2 vetores de strings através do primeiro elemento de cada vetor.
 * 
 * @param x 
 * @param y 
 * @return int 
 */
int compareGroup(const void *x, const void *y){
    char **g1 = *((char ***) x);
    char **g2 = *((char ***) y);
    
    return strcmp(g1[0], g2[0]);
}

/**
 * @brief Aloca e retorna uma matriz de strings (não alocadas) de tamanho (k x n).
 * 
 * @param k Número de linhas
 * @param n Número de colunas
 * @return char*** 
 */
char ***newGroupMatrix(int k, int n){
    char ***groupMatrix = malloc(sizeof(char **) * k);

    for (int i = 0; i < k; i++){
        groupMatrix[i] = malloc(sizeof(char *) * n);
    }

    return groupMatrix;
}

/**
 * @brief Libera uma matriz de k linhas
 * 
 * @param matrix 
 * @param k 
 */
void deleteGroupMatrix(char ***matrix, int k){
    for (int i = 0; i < k; i++){
        free(matrix[i]);
    }

    free(matrix);
}

/**
 * @brief Escreve num arquivo as strings de uma matriz com k linhas e no máximo n colunas em cada linha
 * 
 * @param matrix 
 * @param k número de linhas
 * @param n número de colunas
 * @param output 
 */
void printGroupMatrix(char ***matrix, int k, int n, FILE *output){
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            if (strcmp(matrix[i][j], "\0") == 0){
                break;
            }else if(j != 0){
                fprintf(output, ",");
            }
            fprintf(output, "%s", matrix[i][j]);
        }
        fprintf(output, "\n");
    }
}


/**
 * @brief Organiza os pontos em uma matriz onde cada linha corresponde a um grupo. 
 * Ao final imprime a matriz no arquivo e libera o conteúdo da mesma.
 * 
 * @param list Vetor de pontos
 * @param size Tamanho do vetor de pontos
 * @param k Quantidade de grupos
 * @param output Arquivo a ser escrito
 */
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

    qsort(groupMatrix, k, (sizeof(groupMatrix[0])), compareGroup);

    printGroupMatrix(groupMatrix, k, size, output);
    deleteGroupMatrix(groupMatrix, k);

}