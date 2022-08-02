#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "utils.h"
#include "word_info.h"

typedef struct _Node {
    WordInfo data;
    struct _Node* next;
    struct _Node* prev;
} Node;

typedef struct {
    Node* start;
} LinkedList;

void init_list(LinkedList* l);
void clear_list(LinkedList * l);
void insert_into_list(LinkedList* l, WordInfo c);
Node* find_in_list(LinkedList l, char* word);
int delete_from_list(LinkedList* l, char* word);
void print_list(LinkedList l);

#endif
