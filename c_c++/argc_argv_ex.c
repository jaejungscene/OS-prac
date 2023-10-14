#include <stdio.h>
#include <stdlib.h>
// #include <string.h>
// #include <assert.h>

int main(int argc, char* argv[]){
  // int i =0;
  // for(i=0; i<argc; ++i){
  //   puts(argv[i]);
  // }
  printf("%d\n", argc);
  puts(argv[0]);
  puts(argv[1]);
  puts("End");
  return EXIT_SUCCESS;
}