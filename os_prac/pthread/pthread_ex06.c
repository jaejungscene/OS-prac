#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#define NUM_THREADS 3
#define SIZE 2
#define TIME 5

void *func01(void *threadid){
  int tid = *(int*)threadid;
  printf("start thread %d\n", tid);
  sleep(3);
  pthread_exit(NULL);
}

// void *func02(void *threadid){
//   int tid = *(int*)threadid;
//   printf("start thread %d\n", tid);
//   if(fork()==0)
//   {
//     printf("child PID : %d\n", getpid());
//     sleep(30);
//   }
//   else
//   {
//     printf("child PID : %d\n", getpid());
//     sleep(30);
//   }
//   pthread_exit(NULL);
// }

int main (int argc, char *argv[]){
  pthread_t threads[NUM_THREADS];

  printf("main thread ID : %p\n\n", pthread_self());

  /**** multithread ****/
  pthread_create(&threads[1], NULL, func01, (void *)1);
  // pthread_create(&threads[2], NULL, func02, (void *)2);
  // pthread_join(threads[1], NULL); // main thread wait to join threads[1]
  // pthread_join(threads[2], NULL); // main thread wait to join threads[2]
  sleep(6);

  printf("main thread ID : %p\n", pthread_self());
}