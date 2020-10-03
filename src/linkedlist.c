#include "../include/linkedlist.h"

struct item {
    void *element;
    struct item *next;
};

struct list {
    Item *head;
    Item *tail;
    int length;
};

List* createList() {
    List *l = malloc(sizeof(List));
    l->head = NULL;
    l->tail = NULL;
    l->length = 0;
    return l;
}

Item* createItem(void *element) {
    Item *item = malloc(sizeof(Item));
    item->element = element;
    item->next = NULL;
    return item;
}

void pushToList(List *list, void *element) {
    if (list->head == NULL) {
        Item *item = createItem(element);
        list->head = item;
        list->tail = list->head;
        list->length = 1;
    } else {
        Item *item = createItem(element);
        list->tail->next = item;
        list->tail = item;
        list->length += 1;
    }
}

void deleteList(List *list) {
    Item *p = list->head;
    for (int i = 0; i < list->length; i += 1) {
        list->head = list->head->next;
        free(p);
        p = list->head;
    }
}

int listLength(List *list) {
    return list->length;
}
