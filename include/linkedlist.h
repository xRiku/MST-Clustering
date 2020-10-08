#ifndef _LINKED_LIST_
#define _LINKED_LIST_
#include "point.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct item Item;

typedef struct list List;

struct item {
    Point *element;
    struct item *next;
};

struct list {
    Item *head;
    Item *tail;
    int length;
};

List* createList();

Item* createItem(Point *);

void pushToList(List *, Point *);

void deleteList(List *);

void printList(List *);

int listLength(List *);

Point** linkedListToVector(List * list, int N);

#endif