#include <stdio.h>
#include <mpi/mpi.h>
#include <stdlib.h>
#define MCW MPI_COMM_WORLD

int main(int argc, char *argv[])
{
    int rank, size, err_code, ele, result;
    int mat[3][3];
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MCW, &rank);
    MPI_Comm_size(MCW, &size);
    if (rank == 0)
    {
        printf("Enter the elements in 3x3 matrix:\n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                scanf("%d", &mat[i][j]);
            }
        }
        printf("Enter element to be searched: ");
        scanf("%d", &ele);
    }
    int sMat[3];
    MPI_Bcast(&ele, 1, MPI_INT, 0, MCW);
    MPI_Scatter(mat, 3, MPI_INT, sMat, 3, MPI_INT, 0, MCW);
    int res = 0;
    for (int i = 0; i < 3; i++)
    {
        if (sMat[i] == ele)
            res++;
    }
    MPI_Reduce(&res, &result, 1, MPI_INT, MPI_SUM, 0, MCW);
    if (rank == 0)
    {
        printf("Total number of occurences is: %d\n", result);
    }
    MPI_Finalize();
}