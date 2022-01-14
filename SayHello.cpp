#include <stdio.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char** argv)
{
	int myid, numprocs, namelen;
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	MPI_Init(&argc, &argv); 	// 初始化环境
	//获取并行的进程数
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	//当前进程在所有进程中的序号
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	//获取总的处理机数和各个处理机的名称
	MPI_Get_processor_name(processor_name, &namelen);
	// SAY HELLO TO MPI
	printf("Process %d of %d SAY HELLO TO MPI on %s\n", myid, numprocs,
		processor_name);
	MPI_Finalize(); 	// 退出MPI 环境	
	return 0;
}
