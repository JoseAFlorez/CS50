#include <stdio.h>
#include <cs50.h>
#include <string.h>

long hash(char *str);

int main(void)
{

    //printf("Prueba de Hash\n");
    //printf("Probemos, que palabra quieres usar?\n");
    
    char* word = "pneumonoultramicroscopicsilicovolcanoconiosis";
    long hash_value = hash(word);
    
    printf("Resultado: %lu\n", hash_value);

}


long hash(char *str)
{
	long hash = 5381;
	int c; 
	while ((c = *str++)) 
	{
	    hash = ((hash << 5) + hash) + c; // hash*33 + c
	}
	hash = hash % 100;
	return hash;
}