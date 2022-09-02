#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  for(int i=0; i<argc; i++){
    printf("%s\n", argv[i]);
  }
  printf("We are in Hello.c\n");
  sleep(5);
  printf("PID of hello.c = %d\n", getpid());
  return 0;
}