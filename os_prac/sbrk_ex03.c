#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define ALLIGH 32

typedef struct stru{
   int x;
   char str[10];
}stru;

void* my_malloc(){
   stru *new;
   new->x = 12;
   strcpy(new->str,"hello");
   void* p = sbrk(ALLIGH*2);
   *(stru*)p = *new;

   ((stru*)p)->x = 423;
   printf("p : %p\n", p);
   printf("p->str : %s\n", ((stru*)p)->str);
   printf("p->x : %d\n", ((stru*)p)->x);
   printf("new->x : %d\n\n", (new->x));
   p = p + ALLIGH;

   return p;
}

void print_head(void* ptr){
   ptr = ptr - ALLIGH;

   printf("ptr : %p\n", ptr);
   printf("ptr->str : %s\n", ((stru*)ptr)->str);
   printf("ptr->x : %d\n\n", ((stru*)ptr)->x);
   
}

int main()
{
   void *temp = sbrk(0);
   printf("%p\n", temp);

   temp = my_malloc();
   printf("temp : %p\n", temp);
   printf("temp->str : %s\n", ((stru*)temp)->str);
   printf("temp->x : %d\n\n", ((stru*)temp)->x);

   print_head(temp);

   printf("%d\n", sizeof(stru));

   return 0;
}