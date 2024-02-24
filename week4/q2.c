#include <stdio.h>
#include <mpi/mpi.h>
#include <stdlib.h>
#define MCW MPI_COMM_WORLD

double formula(int x)
{
   return 4.0/ (1.0+(x*x));
}

int main(int argc, char* argv[])
{
    int rank, size, N;
    float result = 0.0, res = 0.0, sres = 0.0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MCW,&rank);
    MPI_Comm_size(MCW, &size);
    sres=formula(rank+1); 
    MPI_Reduce(&sres, &result, 1, MPI_FLOAT, MPI_SUM, 0, MCW);
    if(rank == 0)
    {
        printf("The value of Pi is: %f\n", result);
    }
    MPI_Finalize();
}

