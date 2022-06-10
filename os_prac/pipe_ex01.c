#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#define MSGSIZE 16
char* msg1 = "hello, world #1";
char* msg2 = "hello, world #2";
char* msg3 = "hello, world #3";
  
int main()
{
    char inbuf[MSGSIZE];
    int p[2], pid, nbytes;
  
    if (pipe(p) < 0)
        exit(1);
  
    
    if ((pid = fork()) > 0) 
    { /* parent */
        close(p[0]);
        sleep(5);
        printf("#1 %d\n", getpid());
        write(p[1], msg1, MSGSIZE);
        write(p[1], msg2, MSGSIZE);
        write(p[1], msg3, MSGSIZE);
  
        close(p[1]); // Adding this line will not hang the program
        wait(NULL);
        printf("parent end\n");
    }
    else
    { /* child */
        close(p[1]); // Adding this line will not hang the program
        printf("#2 %d\n", getpid());
        while ((nbytes = read(p[0], inbuf, MSGSIZE)) > 0){
            printf("indugf : %s\n", inbuf);
            printf("nbytes : %d\n", nbytes);
        }
        if (nbytes != 0){
            fprintf(stderr, "ERROR!\n");
            exit(2);
        }
        close(p[0]);
        printf("Finished reading\n");
    }
    return 0;
}