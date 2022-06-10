#include <stdio.h>

static void func1(){
  puts("static func1");
}

void func2(){
  puts("not static func2");
}

int k = 12;