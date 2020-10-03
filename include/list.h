#ifndef _LIST_
#define _LIST_

#include <stdio.h>
#include <stdlib.h>

typedef struct item Item;

typedef struct list List;

List* createList();

Item* createItem();

void pushToList(List *, void *);

void deleteList(List *);

void printList(List *);

#endif