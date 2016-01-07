#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = GetString();
    char first_letter;
    first_letter = name[0];
    printf("%i \n", first_letter-97);
}
