/**
 * @file Process_2.c
 * @author Shreyas Deshpande (shreyasdeshpande12@gmail.com)
 * @brief This is process-2 for solution-2 which acts as shared memory client
 * @version 0.1
 * @date 2023-08-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>

#define SIZE 128
#define KEY  12256

int main()
{
    int shmid =0;
    char *cptr = NULL;
    shmid = shmget(KEY,SIZE,0666);

    cptr = shmat(shmid,NULL,0);

    if(cptr == NULL){
        printf("Failed to attach the shared memory\n");
        return -1;
    }

    printf("Data from shared memory is: \n\n");
    while(*cptr != '\0'){
        
        printf("%c ",*cptr);
        cptr++;
    }
    printf("\n\n");

    
    return 0;
}
