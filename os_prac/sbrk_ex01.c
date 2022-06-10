#include <stdio.h>
#include <unistd.h>

int main()
{
   int* ptr = sbrk(0);
   printf("%p\n", ptr);

   ptr = sbrk(1);
   printf("%p\n", ptr);

   ptr = sbrk(4);
   printf("%p\n", ptr);

   ptr = sbrk(2);
   printf("%p\n", ptr);

   ptr = sbrk(-1);
   printf("%p\n", ptr);

   ptr = sbrk(-1);
   printf("%p\n", ptr);

   ptr = sbrk(1.1);
   printf("%p\n", ptr);

   return 0;
}