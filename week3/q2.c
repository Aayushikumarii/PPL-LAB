#include "mpi.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
	int rank,size,N,M,A[10], C[10], i,length;
	double B[10];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank==0)
	{
		printf("Enter the value of M: \n");
	    scanf("%d", &M);
		N=size;
		length=N*M;
		printf("Enter %d values:\n",length);
		for(i=0; i<length; i++)
		  scanf("%d",&A[i]);
	}
	MPI_Bcast(&M,1,MPI_INT,0,MPI_COMM_WORLD);
	MPI_Scatter(A,M,MPI_INT,C,M,MPI_INT,0,MPI_COMM_WORLD);
	double avg=0,gavg=0;
	for (int i = 0; i < M; i++) 
        avg += C[i];
    avg /= M;
    printf("Process %d Average = %.2f\n", rank, avg);
	MPI_Gather(&avg,1,MPI_DOUBLE,B,1,MPI_DOUBLE,0,MPI_COMM_WORLD);
	if(rank==0)
	{
		for(i=0; i<N; i++)
		{
           gavg+=B[i];
		}
		gavg/=N;
		printf("\nTotal Average= %.2f\n", gavg);
	}
	MPI_Finalize();
	return 0;
}

