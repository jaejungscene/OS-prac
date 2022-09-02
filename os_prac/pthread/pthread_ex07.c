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

int x;  // this data is shared by the thread beacuse it is in data section
void* thread01();  // threads call this function
void* thread02();  // threads call this function

int main(int argc, char *argv[])
{
  pthread_t tid01;  // the thread identifier
  pthread_t tid02;  // the thread identifier
  pthread_attr_t attr;  // set of thread attributes

  printf("main thread ID : %d\n", pthread_self());

  pthread_attr_init(&attr); // get the default attributes
  pthread_create(&tid01, &attr, thread01, NULL); // create the thread
  pthread_create(&tid01, &attr, thread02, NULL); // create the thread
  pthread_join(tid01, NULL);  // wait for the thread to exit
  pthread_join(tid02, NULL);  // wait for the thread to exit

  printf("main thread ID : %d\n", pthread_self());
}

/**
 * local값은 바뀌지 않는데 global variable인 x값은
 * 실행시마다 scheduling 순서로 계속 바뀐다.
 */
void* thread01()
{
  x = 1;
  int local = 32;
  printf("thread01 ID : %d\n", pthread_self());
  printf("thread01 x = %d\n", x);
  printf("thread01 local = %d\n", local);
  pthread_exit(0);
}

void* thread02()
{
  x = 100;
  int local = 11;
  printf("thread02 ID : %d\n", pthread_self());
  printf("thread02 x = %d\n", x);
  printf("thread02 local = %d\n", local); 
  pthread_exit(0);
}