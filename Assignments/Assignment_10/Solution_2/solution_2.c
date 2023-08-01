/*
 *   Write a program which creates two threads,
 *   First thread prints number from 1 to 500,
 *   Second thread prints number from 500 to 1.
 */
#include <stdio.h>
#include <pthread.h>

void *Thread_1(void *ptr)
{
    int i = 0;
    for(i=1;i<=500;i++){
        printf("%d\n",i);
    }

    pthread_exit(NULL);
}

void *Thread_2(void *ptr)
{
    int i=0;

    for(i=500;i>0;i--){
        printf("\t\t%d\n",i);
    }

    pthread_exit(NULL);
}

int main()
{
    pthread_t TID_1, TID_2;
    int Ret1, Ret2;

    Ret1 = pthread_create(&TID_1, NULL, Thread_1, NULL);

    if (Ret1 != 0)
    {
        printf("Failed to create Thread-1\n");
        return -1;
    }

    Ret2 = pthread_create(&TID_2, NULL, Thread_2, NULL);

    if (Ret2 != 0)
    {
        printf("Failed to create Thread-2\n");
        return -1;
    }

    //wait unitl thread-1 ends
    pthread_join(TID_1,NULL);

    //wait until thread-2 ends
    pthread_join(TID_2,NULL);

    //End the main thread
    pthread_exit(NULL);
    return 0;


}
