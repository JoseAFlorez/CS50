#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
    {
        char word[50];
        struct node* next;
    }
    node;

int addNode(char temp_string[50], node *head);

int main (void)
{
    node* head = malloc(sizeof(node));
    head->next = NULL;
    
    //open file and check correct open
    FILE* dic_file = fopen("dictionaries/prueba", "r");
    if (dic_file == NULL)
    {
        printf("Could not open file.\n");
        return 2;
    }
    
    node* hashtable[27];
    
    for(int i = 0; i < 27; i++)
    {
        hashtable[i]->next = NULL;
    }
    
    //read file
    for(int i = 1; i < 27; i++)
    {
        char temp_string[50];
        fscanf(dic_file, "%s", temp_string);
        
        int key = temp_string[0] - 97;
        
        printf("%i\n", key);
        
        addNode(temp_string, hashtable[key]);
        
    }
    
    //if the list is empty
    for(int i = 0; i < 27; i++)
    if (hashtable[i] == NULL)
    {
        printf("List empty.\n");
    }
    
    else  
    {
        //traversal pointer
        node* crawler = hashtable[i];
        
        //until the end of the list
        do
        {
            //keep traversing the list
            crawler = crawler->next;
            printf("%i %s\n", i, crawler->word);
        }
        while (crawler->next != NULL);
        
    }
    
}   

int addNode(char temp_string[50], node *head)
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
        //else loop through the list and find the last
        //node, insert next to it
        node *current = head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newNode;
    }
    return 0;
}


