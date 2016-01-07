# include <stdio.h>
# include <strings.h>
int main(int argc, char *argv[]){

    int i;
    if(argc != 3){
        printf("bad input\n");
        return 1;
    }
    i = strcasecmp(argv[1], argv[2]);
    if (i == 0)
        printf("'%s' equals '%s'\n", argv[1], argv[2]);
    else if (i > 0)
        printf("'%s' is greater than '%s'\n", argv[1], argv[2]);
    else if (i < 0)
        printf("'%s' is less than '%s'\n", argv[1], argv[2]);
    return 0;
}