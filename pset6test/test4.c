#include<stdio.h>
#include<string.h>

//#define size 1
//#define NUMELEM 5

int main(void)
{
    FILE* fd = NULL;

    fd = fopen("test.txt","rw+");

    if(NULL == fd)
    {
        printf("\n fopen() Error!!!\n");
        return 1;
    }

    printf("\n File opened successfully through fopen()\n");
    
    fseek(fd, 0, SEEK_END);
    
    long size = ftell(fd);
    
    printf("size: %ld\n", size);
    
    char* buff = malloc(sizeof(char));
    memset(buff,0,sizeof(buff));
    
    fseek(fd, 0, SEEK_SET);
    
    long sz = fread(buff,size,1,fd);
    
    printf("sz= %ld\n", sz);

    /*if(size != sz)
    {
        printf("\n fread() failed\n");
        return 1;
    }*/

    printf("\n Some bytes successfully read through fread()\n");

    printf("\n The bytes read are [%s]\n",buff);

    if(0 != fseek(fd,11,SEEK_CUR))
    {
        printf("\n fseek() failed\n");
        return 1;
    }

    printf("\n fseek() successful\n");

    if(size*1 != fwrite(buff,size,strlen(buff),fd))
    {
        printf("\n fwrite() failed\n");
        return 1;
    }

    printf("\n fwrite() successful, data written to text file\n");

    fclose(fd);

    printf("\n File stream closed through fclose()\n");

    return 0;
}