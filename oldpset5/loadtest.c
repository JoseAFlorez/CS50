#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

// size of hashtable
const int HSIZE = 500; 

// VARIABLE DEFINITIONS

typedef struct node
    {
        char word[15];
        struct node* next;
    }
    node;
    
typedef struct hash_table
    {
        int size;       
        node** table;
    } 
    hash_table;
    
// PROTOTYPES

int addNode(char* str, hash_table* hashtable);

hash_table* create_hash_table(int size);

node* lookup(hash_table* hashtable, char* str);

//MAIN

int main (void)
{

    //open file and check correct open
    FILE* dic_file = fopen("dictionaries/prueba", "r");
    if (dic_file == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }
    
    //create hashtable
    hash_table* my_hash_table;
    int size_of_table = 27;
    my_hash_table = create_hash_table(size_of_table);
    
    //read file
    char temp_string[15];
    while(EOF != fscanf(dic_file,"%s",temp_string))
    {
        addNode(temp_string, my_hash_table);
    }
    
    //test
    printf("Palabras cargadas correctamente (creo)\n");
    printf("Probemos, que palabra quieres buscar?\n");
    string word = GetString();
    
    node* print_node = lookup(my_hash_table, word);
    
    printf("Se encontro: %s\n", print_node->word);
}


/**********************************
 * FUNCTIONS *
***********************************/

int addNode(char* str, hash_table* hashtable)
{
    node* new_node;
    int key = str[0] - 97;

    // allocate memory for node
    new_node = malloc(sizeof(node));
    
    if (new_node == NULL) 
    {
        return 1;
    }
    
    // insert new node
    strcpy(new_node->word,str);
    new_node->next = hashtable->table[key];
    hashtable->table[key] = new_node;

    return 0;
}

hash_table* create_hash_table(int size) 
{
    hash_table* new_table = malloc(sizeof(hash_table));

    new_table->table = malloc(sizeof(node*) * size); 
    new_table->size = size;

     for (int i = 0; i < size; i++) 
     {
         new_table->table[i] = NULL;
     }

    return new_table;
}

 node* lookup(hash_table* hashtable, char *str)
    {
        node* crawler;
        int key = str[0] - 97;

        for(crawler = hashtable->table[key]; crawler != NULL; crawler = crawler->next) 
        {
            if (strcmp(str, crawler->word) == 0) return crawler;
        }
        return NULL;
    }
