#include "../include/linkedlist.h"

/**
 * @brief Aloca e retorna o ponteiro para uma lista encadeada
 * 
 * @return List* 
 */
List* createList() {
    List *l = malloc(sizeof(List));
    l->head = NULL;
    l->tail = NULL;
    l->length = 0;
    return l;
}

/**
 * @brief Aloca e retorna uma célula de lista encadeada contendo um ponteiro para ponto.
 * 
 * @param element Ponteiro para ponto
 * @return Item* 
 */
Item* createItem(Point *element) {
    Item *item = malloc(sizeof(Item));
    item->element = element;
    item->next = NULL;
    return item;
}

/**
 * @brief Adiciona um ponto no final da lista encadeada.
 * 
 * @param list Ponteiro para lista encadeada
 * @param element Ponteiro para ponto
 */
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

/**
 * @brief Libera a locação da lista encadeada de pontos e de todo o seu conteúdo.
 * 
 * @param list Ponteiro para lista encadeada
 */
void deleteList(List *list) {
    Item *p = NULL;
    for (int i = 0; i < list->length; i++) {
        if(i == 0){
            p = list->head;
        }
        list->head = list->head->next;
        freePoint(p->element);
        free(p);

        p = list->head;
    }
    free(list);
}

/**
 * @brief Retorna o tamanho da lista encadeada.
 * 
 * @param list Ponteiro para lista encadeada
 * @return int 
 */
int listLength(List *list) {
    return list->length;
}

/**
 * @brief Imprime na tela os pontos de uma lista encadeada.
 * 
 * @param list Ponteiro para lista encadeada
 */
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

/**
 * @brief Transfere os pontos de uma lista encadeada para um vetor alocado, liberando a lista.
 * 
 * @param list Ponteiro para lista encadeada
 * @return Point** 
 */
Point** linkedListToVector(List * list){
    Point **vector = (Point **)malloc(sizeof(Point *) * list->length);

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