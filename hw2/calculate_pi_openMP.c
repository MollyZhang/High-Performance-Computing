#include <stdio.h>
#include <sys/time.h>

int main ()
{
    double x, pi, step, start, stop, run_time, sum=0.0, cpu_start, cpu_stop;
    int i;
    int num_steps = 1000000000;
    step = 1./(double)num_steps;

    struct timeval tv;
    gettimeofday(&tv, NULL);

    // start time in milliseconds
    start = (tv.tv_sec)*1000 + (tv.tv_usec)/1000;
    cpu_start = clock();

    #pragma omp parallel for private(x) reduction(+:sum)
    for (i=0; i<num_steps; i++) {
        x = (i + .5)*step;
        sum = sum + 1.0/(1.+ x*x);
    }
    pi = 4.0 * sum * step;
    printf("pi: %f\n", pi);
   
    gettimeofday(&tv, NULL);

    //stop time in milliseconds
    stop = (tv.tv_sec)*1000 + (tv.tv_usec)/1000;
    cpu_stop = clock();
   
    run_time = stop - start; 
    printf("wall time in milliseconds: %f\n", run_time);
    printf("cpu time in milliseconds: %f\n", (cpu_stop - cpu_start)/1000);

    return 0;
}