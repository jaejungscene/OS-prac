#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <time.h>


int main(){
  struct timespec start, finish;
  double elapsed;

  /* 이 clock()처럼 thread의 수가 많아 질수록 
   * time의 속도가 빨라지지 않는다. */
  clock_gettime(CLOCK_MONOTONIC, &start);

  /* ... */
  sleep(2);

  clock_gettime(CLOCK_MONOTONIC, &finish);

  elapsed = (finish.tv_sec - start.tv_sec);
  elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;
  printf("%f sec\n", elapsed);
  // sleep(3);
  printf("finish\n");
  return 0;
}