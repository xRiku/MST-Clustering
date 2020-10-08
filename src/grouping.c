#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/grouping.h"
#include "../include/point.h"

int comparePointGroup(const void *x, const void *y){
    Point *p1 = ((Point*)x);
    Point *p2 = ((Point*)y);
    char *p1SetId = getPointId(getPointSet(p1));
    char *p2SetId = getPointId(getPointSet(p2));

    int compIdSet = strcmp(p1SetId, p2SetId);
    if(compIdSet != 0){
        return compIdSet;
    }else{
        char *p1Id = getPointId(p1);
        char *p2Id = getPointId(p2);
        return strcmp(p1Id, p2Id);
    }
}


