#include <stdio.h>
#include <string.h>
 
#define SIZE 40
 
int main(void)
{
  char buffer1[SIZE] = "computer program";
  char * ptr;
  int    ch = 'p';
 
  ptr = strchr( buffer1, 'p' );
  printf( "The first occurrence of %c in '%s' is '%s'\n",
            ch, buffer1, ptr );

  printf("%p\n", ptr);
  printf("%p\n", &buffer1[3]);
  printf("%p\n\n", &buffer1[9]);
}