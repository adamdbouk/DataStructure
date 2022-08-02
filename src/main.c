#include "utils.h"
#include "hash_table.h"


#define DICTIONARY_FILENAME "../../../../Desktop/Lab2Project/data/data_dict.tsv"
#define FIND_WORDS_FILENAME "../../../../Desktop/Lab2Project/data/data_list.tsv"


int check_linked_list(FILE* fd){
    LinkedList list_test;
    
    int M = 8;
    char *word_array[M];
    word_array[0] = "procedure";
    word_array[1] = "search";
    word_array[2] = "slow";
    word_array[3] = "procedu";
    word_array[4] = "sear";
    word_array[5] = "slo";
    word_array[6] = "fast";
    word_array[7] = "fas";
    
    WordInfo wi;
    
    init_list(&list_test);
    printf("----------------SEARCH IN EMPTY LIST----------------\n");
    for(int i = 0; i < M; i++)
    {
        char* word = word_array[i];

        Node* n = find_in_list(list_test, word);
        if (n == NULL) {
            printf("The word \"%s\" is not in the LinkedList\n", word);
        }else{
            printf("The word \"%s\" is in the LinkedList\n", word);
            wi = n->data;
            print_word_info(wi);
        }          

    }
    
    printf("-------------------------------\n");
   
    if (fd = fopen(DICTIONARY_FILENAME, "r")) {
        int count = 0;
        char line[MAX_LENGTH];
        while (fgets(line, MAX_LENGTH, fd) != NULL) {
            char* ptr = line;
            char* w = mystrsep(&ptr, "\t");
            char* d = mystrsep(&ptr, "\t");
            char c = ptr[0]; //there's a '\n' after that which we just ommit
            str_to_lowercase(w);
            wi = create_word_info(w, d, c);
            insert_into_list(&list_test, wi);
            count++;
        }
        fclose(fd);
        printf("Loaded! There are %d new entries in a LinkedList.\n", count);
        printf("-------------------------------\n");
        printf("Print words from LinkedList:\n");
        printf("-------------------------------\n");
        print_list(list_test);
        printf("----------------SEARCH & REMOVE----------------\n");
        
        for(int i = 0; i < M; i++)
        {
            char* word = word_array[i];
            
            Node* n = find_in_list(list_test, word);
            if (n == NULL) {
                printf("The word \"%s\" is not in the LinkedList\n", word);
            }else{
                printf("The word \"%s\" is in the LinkedList\n", word);
                wi = n->data;
                print_word_info(wi);
            }          
            printf("Removing the word: \"%s\"\n", word);
            bool res = delete_from_list(&list_test, word);
            if (res==TRUE) printf("The word \"%s\" has been removed!\n", word);
            else printf("It is not possible to eliminate this \"%s\"!\n", word);
            printf("-------------------------------\n");
        }
        printf("Print words from LinkedList:\n");
        
        print_list(list_test);        
    } else printf("Error! Could not load data, check file '%s' is not missing.\n", DICTIONARY_FILENAME);
    
}

int main(int argc, char *argv[]) {
    int option;
    HashTable table;
    char word[MAX_WORD_LENGTH];
    char definition[MAX_DEFINITION_LENGTH];
    char category;
    WordInfo wi;
    WordInfo* pwi;
    FILE* fd;

    init_table(&table);
    while (option != 7) {
        printf("1. Insert a word.\n");
        printf("2. Find a word.\n");
        printf("3. Delete a word.\n");
        printf("4. Load words from file.\n");
        printf("5. Find words listed in file.\n");
        printf("6. Display dictionary.\n");
        printf("7. Exit\n");
        printf("(0. LinkedList TEST)\n\n");

        option = -1;
        scan_line("Select an option: ", "%d", &option);
        printf("\n");
    
        switch (option) {
            case 1:
                scan_line("Word: ", "%s", word);
                scan_line("Definition: ", "%s", definition);
                scan_line("Category (N, V, ...): ", "%c", &category);
                str_to_lowercase(word);
                str_to_lowercase(definition);
                wi = create_word_info(word, definition, category);
                if (insert_word_info(&table, wi)) printf("Succeeded!\n");
                else printf("Error! The word \"%s\" already exists.\n", wi.word);
                break;
            case 2: 
                scan_line("Word: ", "%s", word);
                str_to_lowercase(word);
                pwi = find_word_info(table, word);
                if (pwi) {
                    printf("Found!\n");
                    print_word_info(*pwi);
                } else printf("Not found!\n");
                break;
            case 3:
                scan_line("Word: ", "%s", word);
                str_to_lowercase(word);
                bool deleted = delete_word_info(&table, word);
                if (deleted) printf("Deleted!\n");
                else printf("Not found!\n");
                break;
            case 4:
                if (fd = fopen(DICTIONARY_FILENAME, "r")) {
                    int count = 0;
                    char line[MAX_LENGTH];
                    while (fgets(line, MAX_LENGTH, fd) != NULL) {
                        char* ptr = line;
                        char* w = mystrsep(&ptr, "\t");
                        char* d = mystrsep(&ptr, "\t");
                        char c = ptr[0]; //there's a '\n' after that which we just ommit
                        str_to_lowercase(w);
                        wi = create_word_info(w, d, c);
                        if (insert_word_info(&table, wi)) count++;
                    }
                    fclose(fd);
                    printf("Loaded! There are %d new entries.\n", count);
                } else printf("Error! Could not load data, check file '%s' is not missing.\n", DICTIONARY_FILENAME);
                break;
            case 5:
                if (fd = fopen(FIND_WORDS_FILENAME, "r")) {    
                    while (fgets(word, MAX_WORD_LENGTH, fd) != NULL) {
                        word[strcspn(word, "\n")] = '\0'; // remove '\n'
                        str_to_lowercase(word);
                        pwi = find_word_info(table, word);
                        if (pwi == NULL) printf("XXXX %s not found!\n", word);
                        else print_word_info(*pwi);
                    }
                    fclose(fd);
                } else printf("Error! Could not read words, check file '%s' is not missing.\n", FIND_WORDS_FILENAME);
                break;
            case 6:
                print_table(table);
                break;
            case 7:
                printf("Exiting!\n");
                break;
            case 0:
                check_linked_list(fd);
                break;
            default:
                printf("Invalid option.\n");
        }
        printf("\n============================================\n\n");
    }
    clear_table(&table); 
    return 0;
}
