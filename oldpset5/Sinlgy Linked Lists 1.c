#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node* next;
}
node;

node* head = NULL;

void insert_after_third(int to_insert)
{
    //if the list is empty
    if (head == NULL)
    {
        printf("List empty. No 3rd position exists.\n");
    }
    
    else 
    {
        //traversal pointer 
        node* crwler = head;
        
        //set crawler to the third node in the list
        for (int i = 1; i < 3; i++)
        {
            //if already at the end of the list, return
            if (crawler->next == NULL)
            {
                printf("List not long enough. No 3rd position exists.\n");
                return;
            }
            
            //otherwise keep traversing the list
            else crawler = crawler->next;
        }
        
        //initialize a new node to go between the two
        node* new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            printf("Out of memory!\n");
            return;
        }
        
        //plop in the integer value
        new_node->val = to_insert;
        
        //first point our new node's "next" field at the third node's successor
        new_node->next = crawler->next;
        
        //then we can point our previous node's "next" field at the new one
        crawler->next = new_node;
    }
}

void print_last()
{
    //if the list is empty
    if (head == NULL)
    {
        printf("List empty. No last element.\n");
    }
    
    else  
    {
        //traversal pointer
        node* crawler = head;
        
        //until the end of the list
        while (crawler->next != NULL)
        {
            //keep traversing the list
            crawler = crawler->next;
        }
        
        //print the last integer in the list
        printf("The last integer in %d\n", crawler->val);
    }  
}
