#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int data = 13;
int main(){
  int pid = 1;
  // int x = (pid = fork());
  // printf("%d %d\n", pid, x);
  printf("hello %d\n", data);


    /**
     * sleep을 1초라도 해야지 child와 parent
     * process의 printf가 모두 보일 수 있다.
     * 만약 sleep을 하지 않는다면 
     * 자식 프로세스가 printf에 도달하기도 전에
     * 부모 프로세스가 terminate되면서 
     * 자식 process도 같이 terminate될 수 있기 때문이다.
     **/

    /**
     * wait() system call을 쓰지 않았기 때문에
     * 이 program에서 나온 parent process는 child process가
     * exit하는지에 대해선 상관하지 않고 그냥 자신의 process를 진행한다.
     **/

  if((pid = fork()) == 0){
    /* child */
    sleep(30);
    printf("Child of %d is %d\n",
            getppid(), getpid());
  }
  else{
    /* parent */
    wait(NULL);
    sleep(2);
    printf("I am %d. My child is %d\n",
            getpid(), pid);
  }
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
