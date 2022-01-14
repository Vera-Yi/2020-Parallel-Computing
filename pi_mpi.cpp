#include <stdio.h>
#include <mpi.h>

int main(int argc, char* argv[])
{
	double pi, step, sum, x;
	int size, myid;
	long num_steps = 100000;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Bcast(&num_steps, 1, MPI_INT, 0, MPI_COMM_WORLD);

	step = 1.0 / (double)num_steps;
	sum = 0.0;
	for (int i = myid + 1; i <= num_steps; i += size)
	{
		x = step * ((double)i - 0.5);
		sum = sum + 4.0 / (1,0 + x * x);
	}
	sum = sum * step;
	MPI_Reduce(&sum, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
	if (myid == 0) {
		printf("%0.15f\n", pi);
	}
}