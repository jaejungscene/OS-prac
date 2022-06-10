#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t first_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t second_mutex = PTHREAD_MUTEX_INITIALIZER;

void *do_work_one(void *param)
{
  pthread_mutex_lock(&first_mutex);
  printf("01 get first_mutex\n");
  sleep(1); // 이 code가 거의 대부분 deadlock을 걸리게 함
  pthread_mutex_lock(&second_mutex);
  printf("01 citical section\n");
  pthread_mutex_unlock(&second_mutex);
  pthread_mutex_unlock(&first_mutex);
  pthread_exit(0);
}

void *do_work_two(void *param)
{
  pthread_mutex_lock(&second_mutex);
  printf("02 get second_mutex\n");
  pthread_mutex_lock(&first_mutex);
  printf("02 citical section\n");
  pthread_mutex_unlock(&first_mutex);
  pthread_mutex_unlock(&second_mutex);
  pthread_exit(0);
}

int main(int argc, char *argv[])
{
  pthread_t tid01;
  pthread_t tid02;

  printf("============ main thread ID : %p ============\n", pthread_self());

  pthread_create(&tid01, NULL, do_work_one, NULL);
  pthread_create(&tid02, NULL, do_work_two, NULL);
  pthread_join(tid01, NULL);  // wait for the thread to exit
  pthread_join(tid02, NULL);  // wait for the thread to exit

  printf("============ last thread ID : %p ============\n", pthread_self());

  return 0;
}