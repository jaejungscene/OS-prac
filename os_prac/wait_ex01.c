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
  printf("hello %d\n", data);

  /**
   * parent process가 먼저 끝남에도 불구하고
   * child process가 끝날 때까지 5초를 기다린 후
   * parent process 마지막으로 process를 끝낸다.
   */

  pid_t cpid = 0;
  int exit_status = 0;
  if((pid = fork()) == 0){
    /* child */
    printf("====== child ======\n");
    printf("Child of %d is %d\n",
            getppid(), getpid());
    sleep(30);
    printf("== child finish ==\n");
    // exit(1);
    return 0;
  }
  else{
    /* parent */
    // sleep(1);
    printf("====== parent ======\n");
    cpid = wait(&exit_status);  /* import part!!!! */
    if(WIFEXITED(exit_status))  // 자식 process가 오류없이 정상종료
      printf("safe exit in child process : %d\n", exit_status);
    else
      printf("some error occur in child process : %d\n", exit_status);
    printf("I am %d. My child is %d\n",
            getpid(), pid);

    printf("terminated child PID : %d\n", cpid);
    printf("last PID : %d\n", getpid());
    printf("== parent finish ==\n");
    return 0;        
  }
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