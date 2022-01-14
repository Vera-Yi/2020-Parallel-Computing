#include "stdio.h"
#include "omp.h"
#include "iostream"
#include "tchar.h"

static long num_steps = 2000;
double step;

#define NUM_THREADS 8

int _tmain(int argc, char* argv[])
{
	int i;
	double x, pi, sum[NUM_THREADS];
	step = 1.0 / (double)num_steps;
	omp_set_num_threads(NUM_THREADS);

#pragma omp parallel
	{
		double x;
		int tid;
		tid = omp_get_thread_num();
		for (i = tid, sum[tid] = 0.0; i < num_steps; i = i + NUM_THREADS)
		{
			x = (i + 0.5) * step;
			sum[tid] += 4.0 / (1.0 + x * x);
		}
	}

	for (i = 0, pi = 0.0; i < NUM_THREADS; i++)
		pi += sum[i] * step;

	printf("pi is %f\n", pi);

	system("pause");
	return 0;
}
