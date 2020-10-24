#include "../include/unionFind.h"

/**
 * @brief Retorna a componente conexa, dada por outro ponto, em que o ponto se encontra.
 * 
 * @param p 
 * @return Point* 
 */
Point* UFFind(Point* p){
    Point *q = getPointSet(p);
    while(q != getPointSet(q)){
        setPointSet(q, getPointSet(getPointSet(q)));
        q = getPointSet(q);
    }
    return q;
}

/**
 * @brief Une 2 pontos usando o algoritmo "Weighted Quick-Union with Path Compression"
 * 
 * @param p 
 * @param q 
 */
void UFUnion(Point* p, Point* q){
    Point* i = UFFind(p);
    Point* j = UFFind(q);
    if(i == j){
        return;
    }
    int iTreeSize = getTreeSize(i);
    int jTreeSize = getTreeSize(j);
    int totalSize = iTreeSize + jTreeSize;
    if(iTreeSize < jTreeSize){
        setPointSet(i, j);
        setTreeSize(j, totalSize);
    }else{
        setPointSet(j, i);
        setTreeSize(i, totalSize);
    }
}