#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  printf("PID of example.c = %d\n", getpid());
  char command[] = "python3";
  char *args[] = {"./hello.py", NULL};

  sleep(1);
  printf("--\n");
  execv(command, args); //  important part!!!
  printf("Back to example.c");
  return 0;
}