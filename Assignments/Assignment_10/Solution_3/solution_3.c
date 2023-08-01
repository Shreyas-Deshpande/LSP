/*
*   Write a program which creates single thread,
*   We ahve to pass a parameter to that thread from main thread
*/

#include<stdio.h>
#include<pthread.h>

void*Thread_1(void*ptr){
    
    printf("The parameter received from main thread is %d\n",(int)ptr);

    pthread_exit(NULL);
}

int main(){
    int Ret = 0;
    pthread_t TID = 0;
    int iNo = 483;

    Ret = pthread_create(&TID,NULL,Thread_1,(int*)iNo);

    if(Ret != 0){
        printf("Failed to create new thread\n");
        return -1;
    }

    pthread_join(TID,NULL);

    pthread_exit(NULL);

    return 0;
}
