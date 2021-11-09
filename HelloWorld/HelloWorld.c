#include<stdio.h>
#include<omp.h>

void main(){
    #pragma omp parallel{
        printf("Hello World.. THREAD ID: %d", OMP_GET_THREAD_NUM());
    }
}