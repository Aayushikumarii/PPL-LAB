#include"mpi.h"
#include<stdio.h>
#include<math.h>
int main(int argc , char *argv[]){
int rank,size;

MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_rank(MPI_COMM_WORLD,&size);
int x=4;
int ans=pow(x,rank);
int newRank= rank;
int a=5;
int b=3;
if(newRank==0){
printf("\n %d ",a+b);
}
if(newRank==1)
	printf("\n %d ", a-b);

if(newRank==2)
	printf("\n %d",a*b );
if(newRank==3)
	printf("\n %d ",a/b);
if(newRank==4)
	printf("\n %d ",a%b);


}