#include <stdio.h>
#include <string.h>

int main() {
  char string1[20];
  //char string2[20];

  strcpy(string1, "GET / HTTP/1.1\r\n");
  //strcpy(string2, "GET");
  printf("Return Value is : %d\n", strncmp( string1, "GET", 3));

  return 0;
}