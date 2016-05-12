#include <mpi.h>
#include <stdio.h>

int main (int argc, char **argv)
{
    int i, err, rank, size;
    MPI_Init(&argc, &argv);
//    double time1 = MPI_Wtime();
//    double time2 = MPI_Wtick();
//    printf("%f\n", time1);
//    printf("%f\n", time2);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
 
    printf("Hello, world! from process %d of %d\n", rank, size);

    int MPI_finalize();
    return 0;
}
