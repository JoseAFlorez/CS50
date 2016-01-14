#include <stdio.h>
#include <stdbool.h>

typedef char BYTE;
bool load(FILE* file, BYTE** content, size_t* length);

int main (void)
{
    FILE* file = fopen("/home/ubuntu/workspace/pset6/public/favicon.ico", "r");
    if (file == NULL)
    {
        return -1;
    }

    // load file's content
    BYTE* content;
    size_t length;
    
    if (load(file, &content, &length) == false)
    {
        printf("Houston, tenemos un problema!!\n");
        return -1;
    }
    else
    {
        printf("Parece que todo funciona correcto, capitan!\n");
        return 0;
    }
}

bool load(FILE* file, BYTE** content, size_t* length)
{
    // TODO
    
    *length = sizeof(file);
    //printf("i= %i\n", *length);
    fread(content, *length, 1, file);
    
    return true;
}