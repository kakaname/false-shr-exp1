#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

int __attribute__((aligned(64))) val1;
int __attribute__((aligned(64))) val2;

long int n = 1000000000;

void thread1(){
    val1 = 0;
    for (int i=0;i<n;i++){
        if(i%2 == 0){
            val1 += i;
        }else{
            val1 -= i;

        }
    }
}

void thread2(){
    val2 = 0;
    for (int i=0;i<n;i++){
        if(i%2 == 0){
            val2 += i;
        }else{
            val2 -= i;

        }
    }
}


int main(){

    struct timeval start_time, end_time;

    pthread_t threads[2];
    int i1, i2;
    long t;

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
