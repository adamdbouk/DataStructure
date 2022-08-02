#ifndef WORDINFO_H
#define WORDINFO_H

#include "utils.h"

typedef struct {
    char word[MAX_WORD_LENGTH];
    char definition[MAX_DEFINITION_LENGTH];
    char category;                              
} WordInfo;

WordInfo create_word_info(char* word, char* definition, char pos);
void print_word_info(WordInfo wi);

#endif
