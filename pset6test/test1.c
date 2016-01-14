#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    //"GET /hello.php?name=Jose HTTP/1.1\r\n"
    const char* line = "GET /hello.php?name=Jose HTTP/1.1\r\n";
    char abs_path[8191];
    char query[8191];
    char *temp;
    
    //check for method equal "GET"
    if(strncmp(line, "GET", 3) != 0)
    {
        //error(405);
        return -1;
    }
    
    //check for that request-target begins with "/"
    temp = strchr(line, ' ');
    if(strncmp(temp, " /", 2) != 0)
    {
        //error(501);
        return -1;
    }
    
    //check that request-targets has no '"' in it
    if(strchr(temp, '"') != NULL)
    {
        //error(400);
        return -1;
    }
    
    //check HTTP version
    if(strstr(temp, "HTTP/1.1") == NULL)
    {
        //error(505);
        return -1;
    }
    
    //isolate request-target from line
    char *line2;
    char *HTTP_V;
    
    //identifies the beginning and end of request-target (via '/' and ' ')
                                    //line:GET /hello.php?name=Jose HTTP/1.1
    line2 = strchr (line, '/');     //line2:/hello.php?name=Jose HTTP/1.1
    HTTP_V = strchr (line2, ' ');   //HTTP_V: HTTP/1.1
  
    //allocates memory to hold request_t
    char request_t[HTTP_V - line2 + 1];
    
    //copies the request-target, from line2 to request_t
    strncpy(request_t, line2, HTTP_V - line2); 
    request_t[HTTP_V - line2] = '\0'; //request_t:/hello.php?name=Jose
    
    //check for query
    if (strchr(request_t, '?') == NULL)
    {
        //if there's no '?' symbol, query = '\0' and abs_path = request_t
        query[0] = '\0';
        strcpy(abs_path, request_t);
        printf("abs_path: %s\n", abs_path);
        printf("query: %s\n", query);
        return 0;
    }
    else
    {
        //if the '?' symbol exists, query must be separated
        char *query_temp;
        
        query_temp = strchr (request_t, '?'); ///query_temp:?name=Jose
        
        strcpy(query, query_temp+1);
        
        strncpy(abs_path, request_t, query_temp - request_t); 
        abs_path[query_temp - request_t] = '\0';
        
        printf("abs_path: %s\n", abs_path);
        printf ("query: %s\n", query);
    
        return 0;
    }
}