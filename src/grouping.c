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

    int compIdSet = strcmp(p1SetId, p2SetId);
    if(compIdSet != 0){
        return compIdSet;
    }else{
        char *p1Id = getPointId(p1);
        char *p2Id = getPointId(p2);
        return strcmp(p1Id, p2Id); 
    }
}


void groupAndPrint(Point **list, int size, FILE *output){
    qsort(list, size, (sizeof(list[0])), comparePointGroup);

    Point *group = UFFind(list[0]);
    for (int i = 0; i < size; i++){
        if(group != UFFind(list[i])){
            fprintf(output, "\n");
            group = UFFind(list[i]);
        }else{
            if(i != 0){
                fprintf(output, ",");
            }
        }
        fprintf(output, "%s", getPointId(list[i]));
    }
    fprintf(output, "\n");
    
}