#include <stdio.h>
#include <unistd.h>

int main()
{
   void *temp = sbrk(0);
   printf("%p\n", temp);

   // if allocating 3 bytes, *ptr02 = 'a', the value of *ptr01 is changed to the invalid value.s
   int *ptr01 = sbrk(4);
   *ptr01 = 13;
   printf("%p\n", ptr01);
   printf("%d\n", *ptr01);

   char *ptr02 = sbrk(1);
   *ptr02 = 'a';
   printf("%p\n", ptr02);
   printf("%c\n", *ptr02);

   printf("%p\n", ptr01);
   printf("%d\n", *ptr01);

   return 0;
}