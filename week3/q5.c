#include "mpi.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
	int rank,size,N,A[10], C[10], i,length;
	int B[10];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank==0)
	{
		N=size;
		printf("Enter %d values:\n",N);
		for(i=0; i<N; i++)
		  scanf("%d",&A[i]);
	}
	MPI_Scatter(A,1,MPI_INT,C,1,MPI_INT,0,MPI_COMM_WORLD);
	int ec=0,oc=0;
	for (int i = 0; i < N; i++) 
	{
		if(C[i]%2==0)
		{
           C[i]=1;
           ec++;
		}
		else
		{
			oc++;
			C[i]=0;
		}
	}
	MPI_Gather(C,1,MPI_INT,B,1,MPI_INT,0,MPI_COMM_WORLD);
	if(rank==0)
	{
		printf("The Result gathered in the root \n");
		for(i=0; i<N; i++)
		fprintf(stdout,"%d \t",B[i]);
	    printf("Even count %d\n", ec);
	    printf("Odd count %d\n", oc);
	}
	MPI_Finalize();
	return 0;
}
