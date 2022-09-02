/**
 * the system() function is a C standard library function
 * that puts the fork(), exec(), and wait() functions together
 * into a single convenient call
 **/
#include <stdio.h>
#include <stdlib.h>

int main()
{
   printf("Ready to system()...\n");
   printf("=================================\n");
   system("ls");
   printf("=================================\n");
   printf("finish system()\n");
   return 0;
}