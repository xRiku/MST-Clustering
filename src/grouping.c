#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/grouping.h"
#include "../include/unionFind.h"

int comparePointGroup(const void *x, const void *y){
    Point *p1 = *((Point **) x);
    Point *p2 = *((Point **) y);

    char *p1SetId = getPointId(UFFind(p1));
    char *p2SetId = getPointId(UFFind(p2));

    int compIdSet = strcmp(p1SetId, p2SetId); // Essa comparação ta cagando
    if(compIdSet != 0){
        return compIdSet;
    }else{
        char *p1Id = getPointId(p1);
        char *p2Id = getPointId(p2);
        return strcmp(p1Id, p2Id); // Essa aqui ta certa
    }
}


void groupAndPrint(Point **list, int size){
    // ta dando segfault aqui
    qsort(list, size, (sizeof(list[0])), comparePointGroup);

    // printf("\n%p\n", (Point *)list[1]);
    printPointVector(list, size);
}