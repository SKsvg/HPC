#include <stdio.h>
#include <mpi.h>
int main(int argc, char *argv[])
{
	int rank, size;
	MPI_Init(&argc, &argv); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); //initialize address of rank
	MPI_Comm_size(MPI_COMM_WORLD, &size); //initialize address of size
	printf("Hello from process %d of %d\n", rank, size);  //Hello from process 1 of 4
	MPI_Finalize();
	return 0;
}
