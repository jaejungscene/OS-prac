#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/** man pthread

 * int pthread_create(pthread_t *thread,
             const pthread_attr_t *attr,
             void *(*start_routine)(void *), void *arg)
  
 * void pthread_exit(void *value_ptr)
             Terminates the calling thread.

 * int pthread_join(pthread_t thread, void **value_ptr)
             Causes the calling thread to wait for the
             termination of the specified thread.

 * pthread_t pthread_self(void)
             Returns the thread ID of the calling thread.

 */

int sum;  // this data is shared by the thread beacuse it is in data section
void *runner(void *param);  // threads call this function

int main(int argc, char *argv[])
{
  pthread_t tid;  // the thread identifier
  pthread_attr_t attr;  // set of thread attributes

  if(argc != 2){
    fprintf(stderr, "usage: a.out <integer value>\n");
    return -1;
  }
  if(atoi(argv[1]) < 0){
    fprintf(stderr, "%d must be >= 0\n", atoi(argv[1]));
    return -1;
  }

  printf("main thread ID : %d\n", pthread_self());

  pthread_attr_init(&attr); // get the default attributes
  pthread_create(&tid, &attr, runner, argv[1]); // create the thread
  pthread_join(tid, NULL);  // wait for the thread to exit

  printf("sum = %d\n", sum);

  printf("last thread ID : %d\n", pthread_self());
}

void* runner(void *param)
{
  int i, upper = atoi(param);
  sum = 0;

  for(i=1; i<=upper; i++)
    sum += i;
    
  sleep(1);
  printf("runner thread ID : %d\n", pthread_self());
  pthread_exit(0);
}