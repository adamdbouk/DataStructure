#include "word_info.h"


WordInfo create_word_info(char* word, char* definition, char category) {
    //Donats els indicats elements aquesta funció crea un objecte del tipus WordInfo.        
    WordInfo* wi = (WordInfo*) malloc(sizeof(WordInfo)); //Reservem espai que lliurarem un cop eliminem el node.
    strcpy(wi->word, word); //Fem una copia de la paraula.
    strcpy(wi->definition, definition);
    wi->category= category;
    return *wi;
}

void print_word_info(WordInfo wi) {
    // Donat un objecte tipus WordInfo aquesta funció printeja el seu contingut.
    printf("%s (%c): %s\n", wi.word, wi.category, wi.definition);
}
