#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#define MSGSIZE 16

int main()
{
  char buff[MSGSIZE];
  int p[2], pid, check;

  if (pipe(p) < 0){
    fprintf(stderr, "ERR : pipe is failed!!\n");
    exit(1);
  }

  if ((pid = fork()) > 0)
  { /* parent */
    while(1)
    {
      printf("parent >> ");
      scanf("%s", buff);
      check = write(p[1], buff, MSGSIZE);
      if(check == -1){
        fprintf(stderr, "ERR : write is failed!!\n");
        continue;
      }
      break;
    }
    while(1)
    {
      check = read(p[0], buff, MSGSIZE);
      if(check == -1){
        fprintf(stderr, "ERR : read is failed!!\n");
        break;
      }
      printf("parent buff : %s\n", buff);
      break;
    }

    close(p[1]);
    close(p[0]);
    printf("---- parent end ----\n");
  }
  else
  { /* child */
    while(1)
    {
      sleep(1);
      printf("child >> ");
      scanf("%s", buff);
      check = write(p[1], buff, MSGSIZE);
      if(check == -1){
        fprintf(stderr, "ERR : write is failed!!\n");
        continue;
      }
      break;
    }
    while(1)
    {
      check = read(p[0], buff, MSGSIZE);
      if(check == -1){
        fprintf(stderr, "ERR : read is failed!!\n");
        break;
      }
      printf("child buff : %s\n", buff);
      break;
    }

    close(p[0]);
    close(p[1]);
    printf("---- child end ----\n");
  }
  return 0;
}