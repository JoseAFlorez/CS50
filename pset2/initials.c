#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = GetString();
    char first_letter;
    first_letter = toupper(name[0]);
    printf("%c", first_letter);
    for(int j = 0, n=strlen(name); j < n; j++)
    {
        if (name[j] == ' ')
        {
            first_letter = toupper(name[j + 1]);
            printf("%c",first_letter);
        }
    }
    printf("\n");
}
