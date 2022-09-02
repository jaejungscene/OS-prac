// #define process


#ifdef process

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int x = 12;
int main(int argc, char *argv[])
{
  int y = 4;
  if(fork() == 0)
  {
    printf("PID = %d\n", getpid());
    printf("x = %d\n", x);
    x = 13;
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    y = 7;
    printf("y = %d\n", y);
    sleep(3);

    char *args[] = {"ls", "-l", NULL};
    printf("----------------------\n");
    execvp("ls", args); //  important part!!!

    printf("fail to thread01 of command\n");
  }
  else
  {
    wait(NULL);
    printf("----------------------\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("child finished\n");
    printf("parent finished\n");
  }

  return 0;
}

#else

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#define NUM_THREADS 3
#define SIZE 2
#define TIME 30

void *thread01(){
  printf("i'm thread01 : %p\n", pthread_self());
  sleep(TIME);
  pthread_exit(NULL);
}

/**
 * thread02 하나만 duplicate하여 fork()를 수행한다.
 * 전체 process의 thread를 fork()하지 않는다.
 */
void *thread02(){
  printf("i'm thread02 : %p\n", pthread_self());
  if(fork() == 0){
    printf("child PID = %d\n", getpid());
    printf("child thread ID = %p\n", pthread_self());
    sleep(TIME);
  }
  else{
    printf("parent PID = %d\n", getpid());
    printf("parent thread ID = %p\n", pthread_self());
    sleep(TIME);
    printf("thread02 finish!\n");
  }
  pthread_exit(NULL);
}

int main (int argc, char *argv[]){
  pthread_t threads[NUM_THREADS];

  printf("main thread ID : %p\n\n", pthread_self());

  /* multithread */
  pthread_create(&threads[0], NULL, thread01, NULL);
  pthread_create(&threads[1], NULL, thread02, NULL);
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);

  printf("\n----------- finish main!! -------------");

}

#endif