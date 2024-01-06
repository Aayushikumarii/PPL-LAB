#include "mpi.h"
#include<stdio.h>
#include<math.h>
int main(int argc, char *argv[])
{
	int rank; 
	double x=2;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	printf("My rank is %d \n", rank);
	printf("The power is %f \n",pow(x,rank));
	MPI_Finalize();
	return 0;
}