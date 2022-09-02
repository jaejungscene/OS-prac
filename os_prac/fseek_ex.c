#include <stdio.h>
#include <string.h>

int main()
{
   FILE *fpt;
   int x = 0;
   char text[50] = "a";
   fpt = fopen("data.txt", "r");

   x = fread(text, 2, 2, fpt);
   printf("%d\n", x);
   printf("%s\n", text);

   fseek(fpt, 1, SEEK_SET);
   x = fread(text, 2, 2, fpt);
   printf("%d\n", x);
   printf("%s\n", text);

   fseek(fpt, -2, SEEK_CUR);
   x = fread(text, 2, 2, fpt);
   printf("%d\n", x);
   printf("%s\n", text);

   fseek(fpt, -6, SEEK_END);
   x = fread(text, 2, 2, fpt);
   printf("%d\n", x);
   printf("%s\n", text);

   printf("ftell %ld\n", ftell(fpt));

   fclose(fpt);

   return 0;
}