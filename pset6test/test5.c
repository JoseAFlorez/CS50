#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i = 10;
    int* test;
    while(test = malloc(i++) && i < 100)
    {
        printf("%zu - %zu\n", sizeof test, sizeof *test);
    }
}