#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char **argv)
{
    int size, rank;
    char secret_msg_rank0[100] = "secret message";
    char secret_msg_rank1[100];
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank==0)
    {
    	MPI_Send(secret_msg_rank0, 
    		100, MPI_COMPLEX, 1, 0, MPI_COMM_WORLD);
	    printf("The secret message I have is: %s\n", secret_msg_rank0);
    }
    else if (rank == 1)
    {
    	MPI_Recv(&secret_msg_rank1, 
    		100, MPI_COMPLEX, 0, 0, MPI_COMM_WORLD, &status);
	    printf("The secret message I have is: %s\n", secret_msg_rank1);
    }


    printf("Hello reporting from rank %d of %d\n", rank, size);

    int MPI_finalize();
    return 0;
}
