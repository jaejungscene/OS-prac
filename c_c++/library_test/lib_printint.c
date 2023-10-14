//라이브러리 object file을 만들기 위해선 반드시 파일이름 앞쪽에 lib를 붙여주어야 한다!!!
//그리고 main file과 링크하는 과정에서는 앞의 lib을 빼주어야 한다!!!
#include <stdio.h>

void PrintInt(int x){
    printf("\nPrintInt() : %d\n", x);
};