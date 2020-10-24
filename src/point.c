#include "../include/point.h"
#include "../include/unionFind.h"
#include <stdio.h>
#include <string.h>

struct p{
    char* id;
    double* mValues;
    int m;
    int treeSize;
    Point *set;
};

/**
 * @brief Cria e retorna um ponto alocado dinamicamente
 * 
 * @param id String referente ao id do ponto (char *)
 * @param m Dimensão do ponto (int) 
 * @param mValues Vetor de coordenadas (double *)
 * @return Point* 
 */
Point *createPoint(char* id, int m, double* mValues){
    Point *point = malloc(sizeof(Point));
    point->m = m;
    point->id = malloc((1 + strlen(id)) * sizeof(char));
    strcpy(point->id, id);
    point->mValues = mValues;
    point->treeSize = 0;
    point->set = point;
    return point;
}

/**
 * @brief Libera a alocação de um ponto
 * 
 * @param point
 */
void freePoint(Point *point){
    free(point->id);
    if(point->mValues != NULL){
        freePointCoord(point);
    }
    free(point);
}

/**
 * @brief Libera somente o vetor de coordenadas de um ponto
 * 
 * @param point 
 */
void freePointCoord(Point *point){
    free(point->mValues);
    point->mValues = NULL;
}

/**
 * @brief Imprime um ponto e suas informações na tela
 * 
 * @param point 
 */
void printPoint(Point *point){
    printf("Id: %s\n", point->id);
    for (int i = 0; i < point->m; i++)
    {
        printf("%lf ", point->mValues[i]);
    }
    printf("Set: %s", UFFind(point)->id);
    printf("\n");
}

/**
 * @brief Retorna o vetor de coordenadas de um ponto
 * 
 * @param point 
 * @return double* 
 */
double *getPointCoordinates(Point *point) {
    return point->mValues;
}

/**
 * @brief Retorna a dimensão de um ponto
 * 
 * @param point 
 * @return int 
 */
int getPointDimension(Point *point) {
    return point->m;
}

/**
 * @brief Retorna a string id de um ponto
 * 
 * @param point 
 * @return char* 
 */
char *getPointId(Point *point) {
    return point->id;
}

/**
 * @brief Retorna o set de um ponto
 * 
 * @param point 
 * @return Point* 
 */
Point *getPointSet(Point *point) {
    return point->set;
}

/**
 * @brief Define o set de um ponto
 * 
 * @param point Ponto a ter o set definido
 * @param set Ponto que servirá de set
 */
void setPointSet(Point *point, Point *set){
    point->set = set;
}

/**
 * @brief Retorna o tamanho da árvore conexa do ponto
 * 
 * @param point 
 * @return int 
 */
int getTreeSize(Point *point){
    return point->treeSize;
}

/**
 * @brief Define o tamanho da árvore conexa do ponto
 * 
 * @param point 
 * @param size 
 */
void setTreeSize(Point *point, int size){
    point->treeSize = size;
}

/**
 * @brief Função comparadora pra ser usada no qsort().
 * Compara dois pontos com base nos seus IDs.
 * 
 * @param p1 
 * @param p2 
 * @return int
 * 
 */
int comparePointId(const void *p1, const void *p2){
    char *val1 = ((Point*)p1)->id;
    char *val2 = ((Point*)p2)->id;
    
    return strcmp(val1, val2);
    
}

/**
 * @brief Imprime todos os pontos de um vetor de pontos
 * 
 * @param x Vetor de ponteiros para ponto
 * @param size Tamanho do vetor
 */
void printPointVector(Point **x, int size){
    for (int i = 0; i < size; i++)
    {
        printPoint(x[i]);
    }
}

/**
 * @brief Libera a alocação de um vetor de pontos, incluindo a de cada ponto
 * 
 * @param x Vetor de ponteiros para ponto
 * @param size Tamanho do vetor
 */
void deletePointVector(Point **x, int size){
    for (int i = 0; i < size; i++)
    {
        freePoint(x[i]);
    }
    free(x);
}