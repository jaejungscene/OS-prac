#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
 
#define SIZE 40
 
int main(void)
{
  char command[50] = {"ls\0-l\0|\0grep\0test\0"};
  char *tokens[10] = {NULL};
  tokens[0] = &command[0];
  tokens[1] = &command[3];
  tokens[2] = NULL;
  tokens[3] = &command[8];
  tokens[4] = &command[13];


  if(fork() == 0){
    int p[2];
    pipe(p); // OS return two file descriptors
             // p[0] refers to the read end of the pipe
             // p[1] refers to the write end of the pipe
    if(fork() == 0){
      sleep(5);
      printf("child2 : %d\n", getpid());
      dup2(p[1], 1); // dup2(int oldfd, int newfd)
                     // allocates a new file descriptor(newfd)
                     // that refers to the same open file description
                     // as the descriptor oldfd.
      execvp(tokens[0], tokens); // ls -l
      fprintf(stderr,"#2 command not found!!!\n");
      exit(2);
    }
    else{
      int cpid;
      sleep(10);
      cpid = wait(NULL);
      close(p[1]);
      dup2(p[0], 0);
      printf("child2 : %d\n", cpid);
      printf("child1 : %d\n", getpid());
      execvp(tokens[3], &tokens[3]); //grep test
      printf("#1 command not found!!!\n");
      exit(2);
    }
  }
  else{
    int status;
    int cpid;
    // sleep(30);
    cpid = wait(&status);
    printf("status : %d\n", status);
    printf("child : %d\n", cpid);
    printf("parent : %d\n", getpid());
    // sleep(2);
    // printf("\n<< parent >>\n");
    // execvp(tokens[3], &tokens[3]);
  }

  printf("\n------- main ---------\n");
  return 0;
}