#include "hash_table.h"


/**
 * Computes the hash key of a word by mapping the first letter to an integer.
 * There are N=26 possible keys (only low-case letters are considered, it is
 * assumed that all capital letters have been changed using lower_case). If a
 * character not in [a-z] is given, -1 is returned.
 * 
 * Returns the hash key (0-25) or -1.
*/
int hash_function(char* word) { 
    // Donat un char* retornem el número segons per quina lletra comença.
    if (word[0] >= 97 && word[0] <= 122){ //Comparem la lletra entre a i z, segons la taula ascii.
        return (word[0] - 97); //Restem 97 per tenir un valor comprès entre 0 i 25.
    }
    else{
        return -1; //Si la paraula no comença per una lletra retornem -1.
    }   
}

/**
 * Initializes the members of the HashTable struct: its size and all the lists
*/
void init_table(HashTable* table) {
    // Aquesta funció rep un paràmetre HashTable* i l'inicialitza amb mida 0.
    table->size = 0;
    for(int i =0; i< N; i++){
        LinkedList newlist;
        init_list(&newlist);
        table->list[i]=newlist;
    }
}

/**
 * Clears all lists leaving the HashTable struct as if it was just initialized.
*/
void clear_table(HashTable* table) {
    // Donat un element tipus HashTable* aquesta funció neteja la HashTable.
    for(int i =0; i< N; i++){
        clear_list(&table->list[i]);
    init_table(table);
    } 
   
}

/**
 * Looks for the WordInfo corresponding to word by checking which list to search
 * and calling find_in_list.
 * 
 * Returns a pointer to the WordInfo if found or NULL otherwise.
*/

WordInfo* find_word_info(HashTable table, char* word) {
    // Donat un element tipus HashTable i un char* aquesta funció retorna NULL si no troba la paraula a la linkedlist o el seu contingut.
    int num = hash_function(word);
    if (find_in_list(table.list[num], word) == NULL){ //Crida la funció per buscar en llistes i compara el que retorna.
        return NULL;
    }else{
        WordInfo* data = &(find_in_list(table.list[num], word)->data);
        return data;
    }                
}

/**
 * Inserts a WordInfo into the table except if a WordInfo with the same word
 * already exists in the table.
 * 
 * Returns TRUE if insertion was succesful or FALSE otherwise.
*/
bool insert_word_info(HashTable* table, WordInfo wi) {
    // Donat un element HashTable* i un WordInfo, aquesta funció comprova si ja existeix la paraula, i sino, l'afegeix.
    int num = hash_function(wi.word);
    if (num == -1){return FALSE;}
    else{
        if (find_word_info(*table, wi.word) == NULL){ //Comprova si està la paraula.
            insert_into_list(&table->list[num], wi);//Si no està la afegeix.
            table->size += 1; //Augmenta el tamany en un.
            return TRUE;
        }else{return FALSE;}
    }
}

/**
 * Deletes the WordInfo corresponding to word from the table by checking from 
 * which list to delete it and calling delete_from_list.
 * 
 * Returns TRUE if a WordInfo for the given word was present in the dictionary
 * and could be deleted succesfully or FALSE otherwise.
*/
bool delete_word_info(HashTable* table, char* word) {
    // Aquesta funció borra una paraula de la nostra hash table.
    int num = hash_function(word);
    if (num == -1){return FALSE;}
    else{
        if(delete_from_list(&table->list[num], word) == TRUE){ //Aquesta funció borra de la llista la paraula, comprovant que existeixi.
            table->size-=1;
            return TRUE;
            
        }else{return FALSE;}
    }
    
}

/**
 * Prints the number of words in the dictionary followed by the information of
 * each word, one per line. In the case that there are no words in the
 * dictionary it prints "The dictionary is empty".
*/
void print_table(HashTable table) {
    //Aquesta funció imprimeix la hash table.
    int i = 0
    if (N == i){
        printf("The dictionary is empty.");
    }
    else {
        for (i < N; i++){
            print_list(table.list[i]);
        }
    }
}
