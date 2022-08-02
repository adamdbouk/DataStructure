#include "linked_list.h"

/**
 * Initializes the start Node pointer so that the list is empty.
*/
void init_list(LinkedList* l) { // Inicialitza el punter a NULL.
    // Implement this function
    l->start = NULL;
}

bool is_empty(LinkedList* l){ //Comproba si està buida, aquesta funció l'hem creat nosaltres per optimitzar codi.
    return l->start == NULL;
}

/**
 * Clears all the nodes of the list, freeing the memory and leaving the list as
 * it would have just been initialized.
*/
void clear_list(LinkedList* l) {
    // Donat un element tipus LinkedList* s'elimina tota la llista.
    Node* curr = l->start;
    Node* aux = NULL;
    while(curr != NULL){
        aux = curr->next;
        free(curr); //Lliberem la memòria.
        curr = aux;
    }
    init_list(LinkedList* l);
}

/**
 * Reserves memory for a new Node and inserts it in the given linked list,
 * changing the start pointer as well as the prev/next pointers accordingly.
*/
void insert_into_list(LinkedList* l, WordInfo c) {
    // Aquesta funció donat un element tipus LinkedList* i un tipus WordInfo reserva memòria i l'insereix a la LinkedList.
    Node* newNode = (Node*) malloc(sizeof(Node)); //Reservem memòria.
    newNode->data = c;
    newNode->next = NULL;
    newNode->prev = NULL;

    newNode->next = l->start;
    
    if (is_empty(l) == TRUE){ //Comprovem si està buida.
        l->start = newNode;
    } else{
        newNode->next = l->start;
        l->start->prev = newNode;
        l->start = newNode;
    }
    
}

/**
 * Iterates over the different nodes searching for a WordInfo that contains the
 * given word.
 * 
 * Returns: A pointer to the node if found or NULL otherwise.
*/
Node* find_in_list(LinkedList l, char* word) {
    // Donat un element tipus LinkedList i un char*, retorna el punter al node si el troba o NULL si no ho fa.
    Node* curr = l.start;
    while(curr != NULL){        
        if (strcmp(word, curr->data.word) == 0){ //Aquesta funció compara dos strings.
            return curr;
        }
        curr = curr->next; //Avancem el while.
   } 
   return NULL;
    
}

/**
 * Given a node and the list it belongs to, it removes it from the list freeing
 * its memory. It accounts for the start, and the prev/next pointers.
*/
void delete_node(LinkedList* l, Node* p) {
    // Donat un element tipus LinkedList* i un tipus Node* aquesta funció elimina el node.
    if (p->prev != NULL){ 
        p->prev->next = p->next;
    }else{
        l->start = p->next;
    }
    if (p->next != NULL){      
        p->next->prev = p->prev;
    }
    free(p); //Llibera la memòria.
}  

/**
 * If a node in the list contains a WordInfo with the given word, it deletes it.
 * 
 * Returns TRUE if a node was deleted and FALSE otherwise.
*/
bool delete_from_list(LinkedList* l, char* word) {
    // Aquesta funció donat un element tipus LinkedList* i un char* elimina un element de la LinkedList.
    Node* curr = find_in_list(*l,word); //Busquem l'element primer.
    if (curr == NULL){return FALSE;} //Si l'element no existeix retornem FALSE.
    else{ delete_node(l, curr); return TRUE;} //Si l'element existeix eliminem el seu node i retornem TRUE.
}

/**
 * Prints all word infos of the list using print_word_info.
*/
void print_list(LinkedList l) {
    // Donat un element element tipus LinkedList aquesta funció imprimeix la llista.
    Node* curr = l.start;
    while(curr != NULL){
        print_word_info(curr->data);
        curr = curr->next;
        }
   } 
    

