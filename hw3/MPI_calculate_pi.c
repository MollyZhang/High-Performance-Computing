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
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    for (i = 0; i < size; i += 1){
	    if (rank==i)
	    {
	    	printf("%d\n",i);
	    }
    }
    int MPI_finalize();
    return 0;
}
