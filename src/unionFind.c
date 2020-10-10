#include "../include/unionFind.h"

Point* UFFind(Point* p){
    Point *q = getPointSet(p);
    while(q != getPointSet(q)){
        setPointSet(q, getPointSet(getPointSet(q)));
        q = getPointSet(q);
    }
    return q;
}

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