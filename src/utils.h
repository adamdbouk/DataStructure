#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 30
#define MAX_DEFINITION_LENGTH 100
#define MAX_LENGTH MAX_WORD_LENGTH+MAX_DEFINITION_LENGTH+5

#define TRUE 1
#define FALSE 0
#define bool int

#define SUCCESS 1
#define ERROR -1

void str_to_lowercase(char* s);
char* mystrsep(char** str_ptr, char* delim);
bool scan_line(char* message, char* format, void* buffer);

#endif /* UTILS_H */

