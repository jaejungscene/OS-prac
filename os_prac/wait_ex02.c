#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int data = 13;
int main(){
  int pid = 1;
  // int x = (pid = fork());
  // printf("%d %d\n", pid, x);
  printf("hello %d\n\n", data);

  /**
   * parent process가 먼저 끝남에도 불구하고
   * child process가 끝날 때까지 5초를 기다린 후
   * parent process 마지막으로 process를 끝낸다.
   */

  pid_t cpid = 0;
  int exit_status = -10;
  if((fork()) == 0){
    /* child */
    // sleep(3);
    char str1[4] = "lfe";
    char str2[4] = "-a";
    char *argv[4] = {NULL};
    argv[0] = str1;
    argv[1] = str2;
    exit_status = execvp(argv[0], argv);
    printf("child : %d\n", exit_status);
    exit(3); // 1
    printf("aslkjfdsasl\n\n");
    // return 200;
  }
  else{
    /* parent */
    // sleep(1);
    cpid = wait(&exit_status);  /* import part!!!! */
    printf("exit status : %d\n", exit_status);
    if(WIFEXITED(exit_status))  // 자식 process가 오류없이 정상종료
      printf("safe exit in child process\n");
    else
      printf("some error occur in child process\n");
    printf("I am %d. My child is %d\n",
            getpid(), cpid);

    printf("terminated child PID : %d\n", cpid);
    printf("last PID : %d\n", getpid());
    return 0;        
  }

  printf("aslkdjf\n");
  return 0;
}


// https://www.geeksforgeeks.org/fork-system-call/
void forkexample0()
{
    fork();
    fork();
    fork();
    printf("hello\n");
}
void forkexample1()
{
    // child process because return value zero
    if (fork() == 0)
        printf("Hello from Child!\n");
  
    // parent process because return value non-zero.
    else
        printf("Hello from Parent!\n");
}

void forkexample2()
{
    int x = 1;
  
    if (fork() == 0)
        printf("Child has x = %d\n", ++x);
    else
        printf("Parent has x = %d\n", --x);
}
//////////////////////////////////////////////////////