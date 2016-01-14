#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE* file = NULL;
  
    file = fopen("test.txt","r");

    if(NULL == file)
    {
        printf("fopen() Error!!!\n");
        return 1;
    }

    printf("File opened successfully through fopen()\n");
    
    char* content;
    
    int i = 0;
    
    content = malloc(sizeof(char));
    
    while (!feof(file)) 
    {
        fread(content, sizeof(char), 1, file);
        i++;
        content = realloc(content, (sizeof(content) + sizeof(char)));
    }
    
    printf("\n The bytes read are [%s]\n",content);

}