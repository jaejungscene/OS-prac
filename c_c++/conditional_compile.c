#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_INPUT 20
#define CONTROL

typedef struct basisNode
{
    char cityName[11];
    // adjLink link;
} basisNode;

short num = 5;
#ifdef CONTROL
void example()
{
    int arr[num];
    for (int i = 0; i < num; i++)
        arr[i] = i;
    for (int i = 0; i < num; i++)
        printf("%d ", arr[i]);
}
#else
void example1()
{
    int arr[num];
    for (int i = 0; i < num; i++)
        arr[num-i-1] = i;
    for (int i = 0; i < num; i++)
        printf("%d ", arr[i]);
}
#endif
typedef union U
{
    int i[2];
    char c[8];
} U;

int main(void)
{
    #ifdef CONTROL
        example();
    #else
        example1();
    #endif

    return 0;
}
