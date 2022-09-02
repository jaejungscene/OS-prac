#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#define NUM_THREADS 3
#define SIZE 2

int arrA [NUM_THREADS*SIZE] = {1,2,3,4,5,6};
int arrB [NUM_THREADS*SIZE] = {1,2,3,4,5,6};
int arrC [NUM_THREADS*SIZE];  //result array

void *sum(void *threadid){
  long tid;
  tid = (long)threadid;
  for(int i = tid*SIZE; i < (tid+1)*SIZE; i++){
    arrC[i] = arrA[i] + arrB[i];
  }
  pthread_exit(NULL);
}

// void initialize(){
//   for(int i=0; i<NUM_THREADS*SIZE; i++){
//     arrA[i] = i;
//     arrB[i] = i;
//     arrC[i] = 0;
//   }
// }


int main (int argc, char *argv[]){
  pthread_t threads[NUM_THREADS];
  long t;
  struct timespec start, finish;
  double elapsed;

  printf("main thread ID : %p\n\n", pthread_self());


  /* multithread calculation */
  // initialize();
  clock_gettime(CLOCK_MONOTONIC, &start);

  for(t=0; t<NUM_THREADS; t++){
    pthread_create(&threads[t], NULL, sum, (void *)t);
    printf("start thread %ld\n", t);
  }
  for(t=0; t<NUM_THREADS; t++){
    pthread_join(threads[t], NULL);
  }

  clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  printf("multi thread spent time : %f sec\n\n", elapsed);
  

  /* single thread calculation */
  // initialize();
  clock_gettime(CLOCK_MONOTONIC, &start);

  for(t=0; t<NUM_THREADS*SIZE; t++){
    arrC[t] = arrA[t] + arrB[t];
  }

  clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  printf("single thread spent time : %f sec\n\n", elapsed);


  printf("main thread ID : %p\n", pthread_self());
}