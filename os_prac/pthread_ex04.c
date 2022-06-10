#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#define NUM_THREADS 3
#define SIZE 2
#define TIME 5



void *func(void* arg){
  int x = (long)arg;
  printf("%d\n", x);
  printf("helo\n");
  // int tid = *(int*)threadid;
  // printf("start thread %d\n", ti);
  // sleep(tid*tid);
  pthread_exit(NULL);
}

int main (int argc, char *argv[]){
  pthread_t threads[NUM_THREADS];
  struct timespec start, finish;
  double elapsed;

  printf("main thread ID : %p\n\n", pthread_self());


  /**** multithread ****/
  // clock_gettime(CLOCK_MONOTONIC, &start);

  int x=10;  // segmentation fault
  long y=10;
#define VALUE 11
  pthread_create(&threads[1], NULL, func, (void *)VALUE);
  // pthread_create(&threads[2], NULL, func, (void *)2);

  pthread_join(threads[1], NULL); // main thread wait to join threads[1]
  // clock_gettime(CLOCK_MONOTONIC, &finish);
  // elapsed = (finish.tv_sec - start.tv_sec);
  // elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  // printf("time #1 : %f sec\n\n", elapsed);

  // pthread_join(threads[2], NULL); // main thread wait to join threads[2]
  // clock_gettime(CLOCK_MONOTONIC, &finish);
  // elapsed = (finish.tv_sec - start.tv_sec);
  // elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  // printf("time #2 : %f sec\n\n", elapsed);


  printf("main thread ID : %p\n", pthread_self());
}