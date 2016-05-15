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

export OMP_NUM_THREADS=5
echo number of threads $OMP_NUM_THREADS
./calculate_pi_openMP.x

export OMP_NUM_THREADS=6
echo number of threads $OMP_NUM_THREADS
./calculate_pi_openMP.x

export OMP_NUM_THREADS=7
echo number of threads $OMP_NUM_THREADS
./calculate_pi_openMP.x

export OMP_NUM_THREADS=8
echo number of threads $OMP_NUM_THREADS
./calculate_pi_openMP.x

export OMP_NUM_THREADS=9
echo number of threads $OMP_NUM_THREADS
./calculate_pi_openMP.x

export OMP_NUM_THREADS=10
echo number of threads $OMP_NUM_THREADS
./calculate_pi_openMP.x
