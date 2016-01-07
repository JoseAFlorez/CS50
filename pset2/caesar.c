#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int CaesarCy(int c_int, int k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Wrong command-line argument!\n");
        return 1;
    }
    else
    {
        char let;
        int k, c_int;
        k = atoi(argv[1]);
        k = k % 26;        
        string word = GetString();
        for(int j = 0, n = strlen(word); j < n; j++)
        {
            c_int = (int) word[j];
            if (word[j] == ' ')
            {
                printf(" ");
            }
            else if (word[j] >= 'a' && word[j] <= 'z')
            {
                c_int = c_int - 96;
                let = CaesarCy(c_int,k);
                let = (char) (let + 96);
                printf("%c",let);
            }
            else if (word[j] >= 'A' && word[j] <= 'Z')
            {
                c_int = c_int - 65;
                let = CaesarCy(c_int,k);
                let = (char) (let + 65);
                printf("%c",let);
            }
            else
            {
                printf("%c",word[j]);
            }
        }
        printf("\n");
    return 0;
    }    
}

int CaesarCy(int c_int,int k)
{
    int n;
    n = c_int + k;
    if (n > 26)
    {
        n = n % 26;
    }
    return n;
}
