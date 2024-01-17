#include "mpi.h"
#include <stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{
	char str[6];
	int rank,size;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Status status;
	if(rank==0)
	{
		printf("Enter word \n");
		scanf("%s", str);
		MPI_Ssend(&str,6,MPI_CHAR,1,1,MPI_COMM_WORLD);
		fprintf(stdout,"rank=%d I have send %s from process 0\n",rank,str);
		MPI_Recv(&str,6,MPI_CHAR,1,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"rank=%d I have received toggled %s in process 0\n",rank,str);
		fflush(stdout);
	}
	else
	{

		MPI_Recv(&str,6,MPI_CHAR,0,1,MPI_COMM_WORLD,&status);
		fprintf(stdout,"rank=%d I have received %s in process 1\n",rank,str);
		for(int i=0;i<strlen(str);i++)
		{
            if(str[i]>=97)
        		str[i]-=32;
            else
        		str[i]+=32;
		}
        fprintf(stdout,"rank=%d I have toggled and send %s from process 1\n",rank,str);
        MPI_Ssend(&str,6,MPI_CHAR,0,1,MPI_COMM_WORLD);
		fflush(stdout);
	}
	MPI_Finalize();
	return 0;
}





















