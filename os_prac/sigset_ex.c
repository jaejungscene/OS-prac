#include <stdio.h>
#include <signal.h>

int main(){
  int t, check;
  sigset_t mask;
  sigset_t mask02; // running할 때마다 처음 할당되는 값이 바뀜 initialize해주어야 함

  printf("==== mask ====\n");
  for(int i=1; i<30; i++){
    t = sigismember(&mask, i);
    // if(t == 1)
      printf("value of %d is active %d\n", i, t);
  }
  printf("\n");

  printf("==== mask02 ====\n");
  for(int i=1; i<30; i++){
    t = sigismember(&mask02, i);
    // if(t == 1)
      printf("value of %d is active %d\n", i, t);
  }
  printf("\n");

  printf("sizeof : %ld\n", sizeof(mask.__val));
  printf("int : %ld\n", sizeof(t));

  t = sigismember(&mask, SIGALRM);
  printf("t before : %d\n\n", t);

  check = sigdelset(&mask, SIGALRM);
  t = sigismember(&mask, SIGALRM);
  printf("check : %d\n", check);
  printf("t after : %d\n\n", t);

  check = sigaddset(&mask, SIGALRM);
  t = sigismember(&mask, SIGALRM);
  printf("check : %d\n", check);
  printf("t after : %d\n\n", t);


  printf("==== mask ====\n");
  for(int i=1; i<30; i++){
    t = sigismember(&mask, i);
    // if(t == 1)
      printf("value of %d is active %d\n", i, t);
  }
  printf("\n");

  printf("==== mask02 ====\n");
  for(int i=1; i<30; i++){
    t = sigismember(&mask02, i);
    // if(t == 1)
      printf("value of %d is active %d\n", i, t);
  }
  printf("\n");

  // for(int i=1; i<30; i++){
  //   t = sigismember(&mask, i);
  //   if(t == 1)
  //     printf("value of %d is active %d\n", i, t);
  // }

  // check = sigemptyset(&mask);

  // printf("\n");
  // for(int i=1; i<30; i++){
  //   t = sigismember(&mask, i);
  //   if(t == 1)
  //     printf("value of %d is active %d\n", i, t);
  // }
  // printf("mask none\n");

  // printf("\n");
  // for(int i=1; i<30; i++){
  //   t = sigismember(&mask02, i);
  //   if(t == 1)
  //     printf("value of %d is active %d\n", i, t);
  // }
  return 0;
}