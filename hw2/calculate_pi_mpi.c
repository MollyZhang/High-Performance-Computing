#include <stdio.h>

int main ()
{
    double x, pi, step, sum=0.0;
    int i;
    int num_steps = 10;
    printf("num_steps %d\n", num_steps);

    //step = 1./(double)num_steps;
    //printf(step);
    //struct timeval tv;
    //gettimeofday(&tv, NULL);

    // start time in milliseconds
    // start = (tv.tv_sec)*1000 + (tv.tv_usec)/1000;

    /* for (i=0; i<num_steps; i++) {
        x = (i + .5)*step;
        sum = sum + 1.0/(1.+ x*x);
    }
    pi = 4.0*sum*step;

    */
    //gettimeofday(&tv, NULL);

    // stop time in milliseconds
    //stop = (tv.tv_sec)*1000 + (tv.tv_usec)/1000;
    return 0;
}
