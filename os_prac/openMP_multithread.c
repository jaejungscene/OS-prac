#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <omp.h>
#include <time.h>
#define SIZE 10000
float data[SIZE][SIZE];

int main() {
	int i, j;
	float sum;
	clock_t before;
	double result;


	sum = 0.0;
	before = clock();
	omp_set_num_threads(SIZE);
#pragma omp parallel
	{
		for (i = 0; i < SIZE; i++)
			data[omp_get_thread_num()][i] = omp_get_thread_num()*i;
	}
#pragma omp parallel
	{
		for (i = 0; i < SIZE; i++)
			sum += data[omp_get_thread_num()][i];
	}
	result = (double)(clock() - before) / CLOCKS_PER_SEC;
	printf("with openMP : %7.5f\n", result);

	
	sum = 0.0;
	before = clock();
	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			data[i][j] = i * j;
	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			sum += data[i][j];
	result = (double)(clock() - before) / CLOCKS_PER_SEC;
	printf("without openMP for cache : %7.5f\n", result);


	sum = 0.0;
	before = clock();
	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			data[j][i] = i * j;
	for (i = 0; i < SIZE; i++)
		for (j = 0; j < SIZE; j++)
			sum += data[j][i];
	result = (double)(clock() - before) / CLOCKS_PER_SEC;
	printf("without openMP : %7.5f\n", result);


	return 0;
}
