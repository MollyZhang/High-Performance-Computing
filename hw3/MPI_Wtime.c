#include <mpi.h>
#include <stdio.h>

int main (int argc, char **argv)
{
    int i, err, rank, size;
    MPI_Init(&argc, &argv);
    double time1 = MPI_Wtime();
    double time2 = MPI_Wtick();
    printf("%f\n", time1);
    printf("%f\n", time2);

    int MPI_finalize();
    return 0;
}
