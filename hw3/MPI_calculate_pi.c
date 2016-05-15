#include <mpi.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char **argv)
{
    int i, size, rank;
    double start_time, end_time;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

	int num_dot_in_circle = 0;
	int n_iteration = 100000;
	int total_count, total_iteration;


	if (rank != 0)
	    {	
	    	srand(rank);
	    	int j;
	    	for (j=0; j<n_iteration; j++)
	    	{
		    	float x = (float)rand()/(float)(RAND_MAX/2) - 1; 
		    	float y = (float)rand()/(float)(RAND_MAX/2) - 1;
		    	float distance_to_center = x * x + y * y;
		    	if (distance_to_center <= 1) {
		    		num_dot_in_circle += 1;
		    	}
	    	}
	    }
    MPI_Reduce(&num_dot_in_circle,
               &total_count,
               1,
               MPI_INT,
               MPI_SUM,
               0,
               MPI_COMM_WORLD);
    MPI_Reduce(&n_iteration,
			   &total_iteration,
               1,
               MPI_INT,
               MPI_SUM,
               0,
               MPI_COMM_WORLD);
    total_iteration -= n_iteration; //no loop on master node
 
    if (rank == 0)        
    {
        float pi = ((double)total_count/(double)total_iteration)*4.0;
        printf("Pi: %f\ntotal count in circle: %i\ntotal count in square: %d\n", pi, total_count, total_iteration);
    }
    int MPI_finalize();
    return 0;
}
