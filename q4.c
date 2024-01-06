#include "mpi.h"
#include<stdio.h>
#include<math.h>
int main(int argc, char *argv[])
{
	int rank;
	char str[6]= "HelLo";
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(str[rank]>='A' && str[rank]<='Z')
		str[rank]=str[rank]+32;
	else
		str[rank]=str[rank]-32;
	printf("Toggled word is %s \n", str);
	MPI_Finalize();
	return 0;
}