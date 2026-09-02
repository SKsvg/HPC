#include <stdio.h>
#include <mpi.h>
int main(int argc, char *argv[])
{
	int rank, size;
	MPI_Init(&argc, &argv); 
	MPI_Comm_rank(MPI_COMM_WORLD, &rank); //initialize address(&) of rank - rank assign it's id
	MPI_Comm_size(MPI_COMM_WORLD, &size); //initialize address(&) of size - size assign it's whole domain size
	printf("Hello from process %d of %d\n", rank, size);  //Hello from process 1 of 4
	MPI_Finalize();
	return 0;
}

//MPI_COMM_WORLD-whole set of communication domain
//MPI_COMM - variable for the domain

==========================================================================
#include <stdio.h>
void half_of(float a, float* half) { //float* half : address being received * says "go to the address and get the value stored there"
	*half = a/2; 
}
int main()
{
	float a = 5, ha;
	half_of(a, &ha);
	printf("Half of %f is %f \n", a, ha);
}

================================================================================
