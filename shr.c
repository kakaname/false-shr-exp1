
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdint.h>

int* val = NULL;
long int n = 1000000000;

void thread1(){
    for (int i=0;i<n;i++){
        if(i%2 == 0){
            val[0] += i;
        }else{
            val[0] -= i;

        }
    }
}

void thread2(){
    for (int i=0;i<n;i++){
        if(i%2 == 0){
            val[1] += i;
        }else{
            val[1] -= i;

        }
    }
}


int main(){

    struct timeval start_time, end_time;

    pthread_t threads[2];
    int i1, i2;
    long t;

    val = aligned_alloc(64, 2*sizeof(int));

    gettimeofday(&start_time, NULL);

    i1 = pthread_create(&threads[0], NULL, thread1, (void *) t);
    i2 = pthread_create(&threads[1], NULL, thread2, (void *) t);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    gettimeofday(&end_time, NULL);

    double outPut = (double)(end_time.tv_sec - start_time.tv_sec) + 
                 (double)(end_time.tv_usec - start_time.tv_usec) / 1000000;

    printf("%.6f,", outPut);
    
    pthread_exit(NULL);

    return 0;




}
