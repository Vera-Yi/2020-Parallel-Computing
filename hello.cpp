#include "stdio.h"
#include "omp.h"
#include "iostream"
#include "tchar.h"

int _tmain(int argc, char* argv[])
{
	int nthreads, tid;
	omp_set_num_threads(8);

#pragma omp parallel private(nthreads,tid)  //开始并行执行
	{
		tid = omp_get_thread_num();
		printf("Hello from parallel. Thread number=%d\n", tid);
		if (tid == 0)
		{
			nthreads = omp_get_num_threads();
			printf("Number of threads is %d\n", nthreads);
		}
	}
	system("pause");
	return 0;
}

