#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
  char *haystack;
  char *needle;
  
  char buf [] = "GET /hello.php?name=Jose HTTP/1.1\r\n";

  haystack = strchr (buf, '/');
  needle = strchr (haystack, ' ');
  
  char k[needle - haystack + 2];
  strncpy(k, haystack, needle - haystack + 2);
  k[needle - haystack] = '\0'; 

  if (haystack != NULL)
  {
    printf ("found ...%s\n", haystack);
    printf ("found ...%s...\n", k);
  }
  return 0;
}