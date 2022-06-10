#include <stdio.h>
#define LENGTH 5

int max(int a, int b){
  if(a > b)
    return a;
  else
    return b;
}

void func(int (*max)(int, int), char *str){
  printf("str = %s\n", str);
  printf("max = %d\n", max(23,11));
}

char __non_preemptive_worker(void* args) {
  for (int i = 0; i < LENGTH; i++)
    printf("%2d) args : %d\n", i, ((int*)args)[i]);
  return 'a';
}

void uthread_create(char (*stub)(void *), void* args) {
  char check = stub(args);
  printf("check : %c\n", check);
}

int main(int argc, char *argv[]){

  int (*func_p)(int, int) = max;
  printf("result = %d\n", func_p(31,2));
  func(max, "hello");

  printf("\n");

  int param[LENGTH] = {3,2,4};
  uthread_create(__non_preemptive_worker, (void *)param);


  return 0;
}