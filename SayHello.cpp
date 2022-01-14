#include <stdio.h>
#include <math.h>
#include <mpi.h>

int main(int argc, char** argv)
{
	int myid, numprocs, namelen;
	char processor_name[MPI_MAX_PROCESSOR_NAME];
	MPI_Init(&argc, &argv); 	// ��ʼ������
	//��ȡ���еĽ�����
	MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
	//��ǰ���������н����е����
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	//��ȡ�ܵĴ�������͸��������������
	MPI_Get_processor_name(processor_name, &namelen);
	// SAY HELLO TO MPI
	printf("Process %d of %d SAY HELLO TO MPI on %s\n", myid, numprocs,
		processor_name);
	MPI_Finalize(); 	// �˳�MPI ����	
	return 0;
}
