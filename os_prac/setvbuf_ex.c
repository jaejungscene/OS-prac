#include <stdio.h>
#include <string.h>
#include <unistd.h>
 
#define  BUF_SIZE  1024
 
int main(void)
{
   char buff[BUF_SIZE];
   memset( (void*)buff, '\0', sizeof( buff ));

   // fprintf(stdout, "Going to set full buffering on\n");

   // setvbuf(stdout, buff, _IOFBF, BUF_SIZE);

   // fprintf(stdout, "This is tutorialspoint.com\n");
   // fprintf(stdout, "This output will go into buff\n");
   // sleep(2);
   // fflush( stdout );

   // setvbuf(stdout, buff, _IONBF, BUF_SIZE);
   
   // fprintf(stdout, "and this will appear when programm\n");
   // fprintf(stdout, "will come after sleeping 5 seconds\n");
   // sleep(2);

   setvbuf(stdout, buff, _IOLBF, BUF_SIZE);

   fprintf(stdout, "and this will appear when programm\n");
   sleep(2);
   fprintf(stdout, "will come after sleeping 5 seconds\n");

   return 0;
}