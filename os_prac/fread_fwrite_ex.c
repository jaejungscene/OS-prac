#include <stdio.h>
#include <string.h>

int main()
{
  FILE *fpt;
  int x = 42;
  char text[50] = "a";
  fpt = fopen("data.txt", "r");

  x = fread(text, 2, 2, fpt);
  printf("%d\n", x);
  printf("%s\n", text);
  // fprintf(stdout, "hello woo\n");
  fclose(fpt);

  return 0;
}