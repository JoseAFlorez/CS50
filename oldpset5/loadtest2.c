#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
    {
        char word[50];
        struct node* next;
    }
    node;
    
int addNode(char* str, node* hashtable);
    
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
    node* hashtable[27];
    
    //read file
    for(int i = 1; i < 27; i++)
    {
        char temp_string[50];
        fscanf(dic_file, "%s", temp_string);
        
        addNode(temp_string, hashtable);
    }
}   

/**********************************
 * FUNCTIONS *
***********************************/

int addNode(char* str, node* hashtable)
{
    node* new_node;
    new_node->next = NULL;
    int key = str[0] - 97;

    /* Insert into list */
    strcpy(new_node->word, str);
    new_node->next = hashtable[key]->next;
    hashtable[key]->next = new_node;

    return 0;
}

/*int addNode(char temp_string[50], node *head)
{

    //create new node
    node *newNode = (node*)malloc(sizeof(node));

    if(newNode == NULL)
    {
        fprintf(stderr, "Unable to allocate memory for new node\n");
        exit(-1);
    }

    strcpy(newNode->word, temp_string);
    newNode->next = NULL;

    //check for first insertion
    if(head->next == NULL)
    {
        head->next = newNode;
    }

    else
    {
        node *current = head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newNode;
    }
    return 0;
}*/