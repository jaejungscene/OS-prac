#include <stdio.h>
#include <stdarg.h>

/** function that has variable arguments **/
int max(int nCount, ...)
{
  int nMax=-9999, nParam=0, i=0;

  va_list pList = NULL;
  printf("pList = %p\n",pList);

  va_start(pList, nCount);
  printf("pList = %p\n",pList);

  for(i =0; i<nCount; i++){
    nParam= va_arg(pList, int);
    printf("%d) %d\n", i,nParam);
    if(nParam > nMax)
      nMax = nParam;
  }
  nParam= va_arg(pList, int);
  printf("end) %d\n", nParam);

  va_end(pList);
  return nMax;
}


int main(int argc, char *argv[])
{
  printf("max : %d\n", max(3, 1, 3, 2));
  // printf("max : %d\n", max(4, 7, 3, 2, 9));
  // printf("max : %d\n", max(5, 10, 7, 3, 2, 9));

  int x= 3;
  printf("%d\n", 7 & (~3));
  return 0;
}