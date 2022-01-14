#include <omp.h>
#include <stdio.h>
#define NUM_THREADS 2
int main()
{
	static long num_steps = 9000;
	double step = 1.0 / (double)num_steps;
	int i, id;
	double pi = 0.0, sum[NUM_THREADS];
	omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
	{
		double x;
		id = omp_get_thread_num();
		for (i = id, sum[id] = 0.0; i < num_steps; i = i + NUM_THREADS)
		{
			x = (i + 0.5) * step;
			sum[id] += 4.0 / (1.0 + x * x);
		}
	}
	for (i = 0;i < NUM_THREADS;i++)
		pi += sum[i]*step;
	printf("%0.15f\n", pi);
}