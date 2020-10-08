#include "../include/unionFind.h"

Point* UFFind(Point* p){
    Point *q = getPointSet(p);
    Point *qSet = getPointSet(q);
    while(q != qSet){
        setPointSet(qSet, getPointSet(qSet));
        q = qSet;
    }
    return q;
}

void UFUnion(Point* p, Point* q){
    Point* i = UFFind(p);
    Point* j = UFFind(q);
    setPointSet(i, j);
}