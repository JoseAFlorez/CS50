#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Wrong command-line argument!\n");
        return 1;
    }
    int keylength = strlen(argv[1]);
    int key[keylength];
    for(int i = 0; i < keylength; i++)
    {
        if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
        {
            key[i] = ((int) argv[1][i]) - 97;
        } 
        else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
        {
            key[i] = ((int) argv[1][i]) - 65;
        }  
        else
        {
            printf("Wrong command-line argument!\n");
            return 1;
        }
    }    
    string word = GetString();
    int k = 0;
    for(int j = 0, n = strlen(word); j < n; j++)
    {
        char AsciiChar;
        int AsciiNum = (int) word[j];
        k = k % keylength;
        if (word[j] >= 'a' && word[j] <= 'z')
        {
            AsciiNum = (AsciiNum + key[k]);
            if (AsciiNum > 122)
            {
                AsciiNum = AsciiNum - 26;
            }
            AsciiChar = (char) AsciiNum;
            printf("%c", AsciiChar);
            k++;
        }
        else if (word[j] >= 'A' && word[j] <= 'Z')
        {
            AsciiNum = (AsciiNum + key[k]);
            if (AsciiNum > 90)
            {
                AsciiNum = AsciiNum - 26;
            }
            AsciiChar = (char) AsciiNum;
            printf("%c", AsciiChar);
            k++;
        }
        else
        {
            printf("%c",word[j]);
        }   
    }       
    printf("\n"); 
    return 0;   
}
