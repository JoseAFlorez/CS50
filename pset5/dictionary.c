/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <ctype.h>

#include "dictionary.h"

// VARIABLE DEFINITIONS

typedef struct node
    {
        char word[50];
        struct node* next;
    }
    node;
    
typedef struct hash_table
    {
        int size;       
        node** table;
    } 
    hash_table;
    
// GLOBAL VARIABLES
    
int word_count = 0;

hash_table* my_hash_table;

/** 
 * Hashing function
 */
 
unsigned int hash(hash_table *hashtable, char *str)
{
    unsigned int hashval;

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }

    hashval = 0;

    for(; *str != '\0'; str++) hashval = *str + (hashval << 5) - hashval;

    return hashval % hashtable->size;
}

/**
 * Adds a node at the end of a linked list
 */

int addNode(char* str, hash_table* hashtable)
{
    node* new_node;
    
    int key = hash(my_hash_table, str);

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

/**
 * Creates a Hash Table
 */

hash_table* create_hash_table(void) 
{
    int size = 8000 ;
    
    hash_table* my_hash_table = malloc(sizeof(hash_table));

    my_hash_table->table = malloc(sizeof(node*) * size); 
    my_hash_table->size = size;

     for (int i = 0; i < size; i++) 
     {
         my_hash_table->table[i] = NULL;
     }

    return my_hash_table;
}

/**
 * Returns true if word is in dictionary else false.
 */
 
bool check(const char* word)
{
    node* crawler;
        
    char* str = malloc(sizeof(char*));
        
    strcpy(str, word);
        
    int key = hash(my_hash_table, str);

    for(crawler = my_hash_table->table[key]; crawler != NULL; crawler = crawler->next) 
    {
        int j = strcasecmp(word, crawler->word);
        if (j == 0) 
        {
            return true;
        }
    }
        
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
 
bool load(const char* dictionary)
{
    //open file and check correct open
    FILE* dic_file = fopen(dictionary, "r");
    if (dic_file == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }
    
    my_hash_table = create_hash_table();
    
    //read file and adds word to dictionary
    char temp_string[50];
    while(EOF != fscanf(dic_file,"%s",temp_string))
    {
        addNode(temp_string, my_hash_table);
        word_count++;
    }

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
 
unsigned int size(void)
{
    if(word_count != 0)
    {
        return word_count;
    }
    else
    {
        return 0;
    }
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
 
bool unload(void)
{
    int i;
    node *node, *temp;

    if (my_hash_table==NULL) 
    {
        return false;
    }
    
    for(i=0; i<my_hash_table->size; i++) 
    {
        node = my_hash_table->table[i];
        while(node!=NULL) 
        {
            temp = node;
            node = node->next;
            free(temp);
        }
    }

    free(my_hash_table->table);
    free(my_hash_table);
    
    return true;
}
