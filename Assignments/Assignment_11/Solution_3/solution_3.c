#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>

int iNum = 50;

void* threadproc(void* ptr){
    int iTemp = (int)ptr;
    int i=0;
    printf("Value of Number before Addition: %d\n",iNum);
    iNum+=iTemp;
    for(i=0;i<65536;i++);
    printf("Value of number after adding %d is: %d\n",iTemp,iNum);

    pthread_exit(NULL);

}



int main(){

    pthread_t TID1 =0 , TID2=0;
    int Ret =0;

    Ret = pthread_create(&TID1,NULL,threadproc,10);
    if(Ret != 0){
        printf("Unable to create thread-1\n");
        return -1;
    }

    Ret = pthread_create(&TID2,NULL,threadproc,40);
    if(Ret != 0){
        printf("Unable to create thread-2\n");
        return -1;
    }

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);

    printf("\n\nExpected result of Thread-1: %d\n",(10+50));
    printf("Expected result of Thread-2: %d\n",(40+60));
    return 0;
}
