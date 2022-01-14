#include <omp.h>
#include <stdio.h>
#define NUM_THREADS 2
int main()
{
	static long num_steps = 100000;
	double step = 1.0 / (double)num_steps;
	int i, id;
	double x, pi = 0.0, sum;
	omp_set_num_threads(NUM_THREADS);
#pragma omp parallel for reductoon(+:sum) private(x)
	for (i = 1; i <= num_steps; i = i++)
	{
		x = (i - 0.5) * step;
		sum = sum + 4.0 / (1.0 + x * x);
	}
	pi = sum * step;
	printf("%0.15f\n", pi);
}