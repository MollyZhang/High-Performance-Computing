#include <mpi.h>
#include <stdio.h>

int i;

int main ()
{
    for (i=1; i<10; i++)
    {
        double time1 = MPI_Wtime();
        printf("%f\n", time1);
    }
    return 0;
}
