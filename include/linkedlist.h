#ifndef _LINKED_LIST_
#define _LINKED_LIST_
#include "point.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct item Item;

typedef struct list List;

List* createList();

Item* createItem(Point *);

void pushToList(List *, Point *);

void deleteList(List *);

void printList(List *);

#endif