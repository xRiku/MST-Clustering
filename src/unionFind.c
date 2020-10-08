#include "../include/unionFind.h"

Point* UFFind(Point* p){
    Point* q = getPointSet(p);
    while(q != getPointSet(q)){
        copyPoint(getPointSet(q), getPointSet(getPointSet(q)));
        copyPoint(q, getPointSet(q));
    }
    return q;
    // Point* q = p->set;
    // while(q != q->set){
    //     q->set = q->set->set;
    //     q = q->set;
    // }
    // return q;
}

void UFUnion(Point* p, Point* q){
    Point* i = UFFind(p);
    Point* j = UFFind(q);
    copyPoint(getPointSet(i), j);
    // Point* i = UFFind(p);
    // Point* j = UFFind(q);
    // i->set = j;
}