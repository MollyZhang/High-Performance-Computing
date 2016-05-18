#include <stdio.h> 
#include <cuda.h>
#include <cuda_runtime_api.h>


int main() {
    int nDevices, i;
    cudaGetDeviceCount(&nDevices);
    printf("There are %d CUDA devices. \n", nDevices);
    for (i = 0; i < nDevices; i++) {
        cudaDeviceProp prop;
        cudaGetDeviceProperties(&prop, i);
        printf("Device Number: %d\n", i);
        printf("Device name: %s\n", prop.name);
	printf("Total global memory: %u\n", prop.totalGlobalMem);
	printf("Total shared memory per block: %u\n",  prop.sharedMemPerBlock);
    	printf("Total registers per block:     %d\n",  prop.regsPerBlock);
    	printf("Warp size:                     %d\n",  prop.warpSize);
    	printf("Maximum memory pitch:          %u\n",  prop.memPitch);
    	printf("Maximum threads per block:     %d\n",  prop.maxThreadsPerBlock);
    	printf("Clock rate:                    %d\n",  prop.clockRate);
    	printf("Total constant memory:         %u\n",  prop.totalConstMem);
    	printf("Number of multiprocessors:     %d\n",  prop.multiProcessorCount);
        printf("Memory Clock Rate (KHz): %d\n", prop.memoryClockRate);
        printf("Memory Bus Width (bits): %d\n", prop.memoryBusWidth);
        printf("Peak Memory Bandwidth (GB/s): %f\n\n",
            2.0*prop.memoryClockRate*(prop.memoryBusWidth/8)/1.0e6);
  }
}
