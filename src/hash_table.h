#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "utils.h"
#include "linked_list.h"

#define N 26          // number of slots in the hash table (number of letters)

typedef struct {
    LinkedList list[N];
    int size;
} HashTable;

void init_table(HashTable* table);
void clear_table(HashTable* table);
bool insert_word_info(HashTable* table, WordInfo wi);
WordInfo* find_word_info(HashTable table, char* word);
bool delete_word_info(HashTable* table, char* word);
void print_table(HashTable table);

#endif
