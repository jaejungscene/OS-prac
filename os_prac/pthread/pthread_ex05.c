#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#define NUM_THREADS 3
#define SIZE 2
#define TIME 5

void *func(void *threadid){
  int tid = *(int*)threadid;
  printf("start thread %d\n", tid);
  sleep(tid*tid);
  pthread_exit(NULL);
}

/** 
 * main thread가 끝나면 process 자체가 종료되기 때문에
 * 남아 있던 thread들도 모두 사라진다.
 * 즉, main thread 상에 join을 해놓지 않으면
 * main thread든 자신의 task만을 실행하고 process를
 * 종료시겨 버린다.
 */
int main (int argc, char *argv[]){
  pthread_t threads[NUM_THREADS];
  struct timespec start, finish;
  double elapsed;

  printf("main thread ID : %p\n\n", pthread_self());


  /**** multithread ****/
  clock_gettime(CLOCK_MONOTONIC, &start);

  pthread_create(&threads[1], NULL, func, (void *)1);
  pthread_create(&threads[2], NULL, func, (void *)2);

  // pthread_join(threads[1], NULL); // main thread wait to join threads[1]
  clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  printf("time #1 : %f sec\n\n", elapsed);

  // pthread_join(threads[2], NULL); // main thread wait to join threads[2]
  clock_gettime(CLOCK_MONOTONIC, &finish);
  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  printf("time #2 : %f sec\n\n", elapsed);


  printf("main thread ID : %p\n", pthread_self());
}