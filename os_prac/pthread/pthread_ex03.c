#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#define NUM_THREADS 3
#define SIZE 2
#define TIME 5

void *sum(void *threadid){
  sleep(TIME);
  pthread_exit(NULL);
}

int main (int argc, char *argv[]){
  pthread_t threads[NUM_THREADS];
  long t;
  struct timespec start, finish;
  double elapsed;

  printf("main thread ID : %p\n\n", pthread_self());


  /**** single thread ****/
  clock_gettime(CLOCK_MONOTONIC, &start);

  sleep(TIME*NUM_THREADS);

  clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  printf("single thread spent time : %f sec\n\n", elapsed);


  /**** multithread ****/
  clock_gettime(CLOCK_MONOTONIC, &start);

  for(t=0; t<NUM_THREADS; t++){
    printf("start thread %ld\n", t);
    pthread_create(&threads[t], NULL, sum, (void *)t);
  }
  
  for(t=0; t<NUM_THREADS; t++){
    pthread_join(threads[t], NULL);
  }

  clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  printf("multi thread spent time  : %f sec\n\n", elapsed);


  printf("main thread ID : %p\n", pthread_self());
}