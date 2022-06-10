/**
 * https://codingfreak.blogspot.com/2009/10/signals-in-linux-blocking-signals.html#:~:text=Blocking%20a%20signal%20means%20telling,is%20said%20to%20be%20pending.
 * 
 * Blocking a signal means telling the operating system 
 * to hold it and deliver it later when it is unblocked.
 * 
 * blocking a signal is different from ignoring a signal. 
 * When a process blocks a signal, 
 * the operating system does not deliver the signal 
 * until the process unblocks the signal. 
 * A process blocks a signal 
 * by modifying its signal mask with sigprocmask. 
 * But when a process ignores a signal, 
 * the signal is delivered and the process handles it 
 * by throwing it away.
 */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
  int i, t;
  sigset_t intmask;
  int repeatfactor;
  double y = 0.0;

  for(int i=0; i<30; i++){
    t = sigismember(&intmask, i);
    if(t == 1)
      printf("value of %d : %d\n", i, t);
  }

  if ((sigemptyset(&intmask) == -1) || (sigaddset(&intmask, SIGINT) == -1) \
                                    || (sigaddset(&intmask, SIGKILL) == -1))
  // if ((sigemptyset(&intmask) == -1))
  {
    perror("Failed to initialize the signal mask");
    return 1;
  }

  printf("\n");
  for(int i=1; i<30; i++){
    t = sigismember(&intmask, i);
    if(t == 1)
      printf("value of %d : %d\n", i, t);
  }

  for (;;)
  {
    printf("Entering BLOCK state\n");
    if (sigprocmask(SIG_BLOCK, &intmask, NULL) == -1)
      break;
    fprintf(stderr, "SIGINT signal blocked\n");
    sleep(100);

    printf("Leaving Blocking State & Entering UNBLOCK state\n");
    if (sigprocmask(SIG_UNBLOCK, &intmask, NULL) == -1)
      break;
    fprintf(stderr, "SIGINT signal unblocked\n");
    sleep(2);
  }
  perror("Failed to change signal mask");
  return 1;
}