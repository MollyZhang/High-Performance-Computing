#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
    int i, size, rank;
    double start_time, end_time;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    for (i = 100; i < 10000000; i *= 2){
	    int *msg_rank0 = (int*)calloc(i, sizeof(char));
	    int *msg_rank1 = (int*)calloc(i, sizeof(char));
	    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	    MPI_Comm_size(MPI_COMM_WORLD, &size);
	    if (rank==0)
	    {
	    	start_time = MPI_Wtime();
	    	MPI_Send(msg_rank0, 
	    		i, MPI_INT, 1, 0, MPI_COMM_WORLD);
	    	MPI_Recv(msg_rank0, 
	    		10000000, MPI_INT, 1, 1, MPI_COMM_WORLD, &status);
	    	end_time = MPI_Wtime();
		    printf("at datasize=%d byte, round trip time of message passing is %f\n", 
		    	i*4, end_time - start_time);
    	    free(msg_rank0);
	    }
	    else if (rank == 1)
	    {
	    	MPI_Recv(msg_rank1, 
	    		10000000, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
	    	MPI_Send(msg_rank1, 
	    		i, MPI_INT, 0, 1, MPI_COMM_WORLD);
		    free(msg_rank1);
	    }
    }
    int MPI_finalize();
    return 0;
}
