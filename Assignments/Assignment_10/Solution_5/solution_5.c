/**
 * @file solution_5.c
 * @author Shreyas Deshpande
 * @brief Write a program which is used to get thread id inside its thread function.
 * @date 2023-08-02
 * 
 */

#include<stdio.h>
#include<pthread.h>

void*ThreadCB(void*ptr){
    pthread_t current_TID = 0;
    
    current_TID = pthread_self();

    printf("Runing Thread ID: %ld\n",current_TID);

    pthread_exit(NULL);
    
}

int main(){
    int Ret = -1;
    pthread_t TID =0;

    Ret = pthread_create(&TID,NULL,ThreadCB,NULL);
    if(Ret != 0){
        printf("Unable to create new thread\n");
        return -1;
    }

    printf("Newly created Thread ID: %ld\n",TID);

    pthread_join(TID,NULL);

    pthread_exit(NULL);

    return 0;
}
