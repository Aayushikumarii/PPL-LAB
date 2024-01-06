#include "mpi.h"
#include<stdio.h>
#include<math.h>
int main(int argc, char *argv[])
{
	int rank;
	int a=2,b=5;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(rank==0)
	{
		printf("Airthematic Operation\n");
		printf("Sum= %d\n", a+b);
		printf("Difference= %d\n",a-b);
		printf("Multiplication= %d\n", a*b);
		printf("Division= %d\n",a/b);
		printf("Remainder= %d\n", a%b);
	}
	else if(rank==1)
	{
		printf("Bitwise Operation\n");
		printf("And %d\n", a&b);
		printf("Or %d\n", a|b);
		printf("XOR%d\n", a^b);

	}
	MPI_Finalize();
	return 0;
}
