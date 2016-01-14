#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#define _GNU_SOURCE

int main (void)
{
    const char* path = "/hello.pHp";
    
    char* j = strrchr(path, '.');

    int i = strcasecmp(j, ".php");
    
    printf("j= %s\n", j);
    printf("i= %i\n", i);
}

