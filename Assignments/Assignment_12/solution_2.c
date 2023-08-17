/**
 * @file solution_2.c
 * @author Shreyas Deshpande (shreyasdeshpande12@gmail.com)
 * @brief Write a program which creates two processes and,
 *          that two processes can communicate with each
 *          other by using concept of shared memory.
 * @version 0.1
 * @date 2023-08-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/shm.h>

#define SIZE 128
#define KEY  12256

int main(){
    int Ret =0, shmid=0;
    char* cptr = NULL;
     
    Ret = fork();

    if(Ret == 0){
        //Inside child
        execl("./process_2","NULL",NULL);
    }
    else{
        //Parent acts as shared memory server
        shmid = shmget(KEY,SIZE,IPC_CREAT|0666);

        cptr = shmat(shmid,NULL,0);

        if(cptr == NULL){
            printf("Failed to attach the shared memory by server\n");
            return 1;
        }

        *cptr = 'G';
        cptr++;
        *cptr = 'a';
        cptr++;
        *cptr = 'n';
        cptr++;
        *cptr = 'a';
        cptr++;
        *cptr = 'p';
        cptr++;
        *cptr = 'a';
        cptr++;
        *cptr = 't';
        cptr++;
        *cptr = 'i';
        cptr++;
        *cptr = ' ';
        cptr++;
        *cptr = 'B';
        cptr++;
        *cptr = 'a';
        cptr++;
        *cptr = 'p';
        cptr++;
        *cptr = 'p';
        cptr++;
        *cptr = 'a';
        cptr++;
        *cptr = ' ';
        cptr++;
        *cptr = 'M';
        cptr++;
        *cptr = 'o';
        cptr++;
        *cptr = 'r';
        cptr++;
        *cptr = 'a';
        cptr++;
        *cptr = 'y';
        cptr++;
        *cptr = 'a';
        cptr++;
        *cptr = '\0';
        
        sleep(20);
    }
    return 0;
}
