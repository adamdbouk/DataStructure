#include "utils.h"

/**
 * Modifies the given string mapping all characters in [A-Z] to [a-z]. 
*/
void str_to_lowercase(char* s){
    //Aquesta funció recorre la paraula introduida i la converteix en minúscules.
    while (*s != '\0'){
        if (*s >= 65 && *s <= 90){ //Mira si és majúscula.
            *s = *s + 32; //Si ho és li suma ho corresponent per a ser minúscula.
        }
        s++;
    }
}

/**
 *  Function strsep is not standard in Windows, we implement our own
*/
char* mystrsep(char** str_ptr, char* delim) {
  if (*str_ptr == NULL) return NULL;
  char* start = *str_ptr;
  *str_ptr = strpbrk(start, delim);
  if (*str_ptr != NULL) {
    **str_ptr = '\0';
    *str_ptr = *str_ptr + 1;
  }
  return start;
}

/**
 * Reads one line from console
*/
bool scan_line(char* message, char* format, void* buffer) {
    printf("%s", message);
    fflush(stdout);
    char line[1000]; // this should be a sufficiently long buffer
    char* res = fgets(line, sizeof(line), stdin);
    if (res == NULL) return FALSE; // reading from stdin failed
    line[strcspn(line, "\n")] = '\0'; // remove '\n'
    if (format == NULL || strcmp(format, "%s") == 0) strcpy(buffer, line);
    else sscanf(line, format, buffer); // we asume here that format is a single specifier (e.g. only %d)
    return TRUE;
}