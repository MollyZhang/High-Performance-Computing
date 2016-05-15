#!/usr/bin/env bash
export OMP_NUM_THREADS=1
echo number of threads $OMP_NUM_THREADS
./calculate_pi_openMP.x

export OMP_NUM_THREADS=2
echo number of threads $OMP_NUM_THREADS
./calculate_pi_openMP.x

export OMP_NUM_THREADS=3
echo number of threads $OMP_NUM_THREADS
./calculate_pi_openMP.x

export OMP_NUM_THREADS=4
echo number of threads $OMP_NUM_THREADS
./calculate_pi_openMP.x

