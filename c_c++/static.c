// https://www.geeksforgeeks.org/what-are-static-functions-in-c/
// https://www.geeksforgeeks.org/static-variables-in-c/

#include<stdio.h>

int fun()
{
  // int count = 0;
  static  int count = 0;

  count++;
  return count;
}

int initilizer(){
  return 14;
}  

int main()
{
  // static int i = initilizer(); ERR!!
  printf("%d ", fun());
  printf("%d ", fun());
  return 0;
}