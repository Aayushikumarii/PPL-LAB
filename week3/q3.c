#include "mpi.h"
#include <stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
	int rank,size,N,A[10], C[10], i,count=0,l;
	int B[10];
	char str[100];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank==0)
	{
		N = size;
        printf("Enter the string: \n");
		scanf("%s", str);
		l = strlen(str) / N;
	}
	MPI_Bcast(&l, 1, MPI_INT, 0, MPI_COMM_WORLD);
	MPI_Scatter(str, l, MPI_CHAR, C, l, MPI_CHAR, 0, MPI_COMM_WORLD);
	for (i = 0; i < l; i++) 
	{
		if (!(C[i]=='a' || C[i]=='e' || C[i]=='i' || C[i]=='o' || C[i]=='u'))
			count += 1;
	}
	printf("Process %d Count = %d\n", rank, count);
	MPI_Gather(&count, 1, MPI_INT, B, 1, MPI_INT, 0, MPI_COMM_WORLD);
	if (rank == 0)
	{
		int tcount = 0;
		for (i = 0; i < N; i++)
			tcount += B[i];
		printf("Total non vowels = %d\n", tcount);
	}
	MPI_Finalize();
}