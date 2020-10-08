#include "../include/linkedlist.h"

List* createList() {
    List *l = malloc(sizeof(List));
    l->head = NULL;
    l->tail = NULL;
    l->length = 0;
    return l;
}

Item* createItem(Point *element) {
    Item *item = malloc(sizeof(Item));
    item->element = element;
    item->next = NULL;
    return item;
}

void pushToList(List *list, Point *element) {
    Item *item = createItem(element);
    if (list->head == NULL) {
        list->head = item;
        list->tail = list->head;
        list->length = 1;
    } else {
        list->tail->next = item;
        list->tail = item;
        list->length += 1;
    }
}

void deleteList(List *list) {
    Item *p = NULL;
    for (int i = 0; i < list->length; i++) {
        if(i == 0){
            p = list->head;
        }
        list->head = list->head->next;
        freePoint(p->element); // Talvez precise ou não dar free nos pontos. Anyway, qualquer coisa ta aqui.
        free(p);

        p = list->head;
    }
    free(list);
}

int listLength(List *list) {
    return list->length;
}

void printList(List *list){

    Item *p = NULL;
    for (int i = 0; i < list->length; i++) {
        if(i == 0){
            p = list->head;
        }
        printPoint(p->element);
        p = p->next;
    }
}


Point** linkedListToVector(List * list, int N){
    Point **vector = (Point **)malloc(sizeof(Point *) * N);

    Item *p = NULL;
    for (int i = 0; i < list->length; i++) {
        if(i == 0){
            p = list->head;
        }
        list->head = list->head->next;
        vector[i] = p->element;
        free(p);

        p = list->head;
    }
    free(list);
    return vector;
}