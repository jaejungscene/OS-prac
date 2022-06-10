#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>


void __scheduler()
{
  printf("** scheduler **\n");
}

#define SCHEDULER_FREQ 1000

int main(int argc, char *argv[])
{
  // int i, t;
  // sigset_t intmask;
  struct sigaction ticker;
  struct itimerval time_quantum; 

  time_quantum.it_interval.tv_sec = 0;
  time_quantum.it_interval.tv_usec = SCHEDULER_FREQ;
  time_quantum.it_value = time_quantum.it_interval;

  ticker.sa_handler = __scheduler;
  sigemptyset(&ticker.sa_mask);
  sigaction(SIGINT, &ticker, NULL);
  ticker.sa_flags = 0;

  setitimer(ITIMER_REAL, &time_quantum, (struct itimerval*)NULL);

  sleep(20);

  return 0;
}


