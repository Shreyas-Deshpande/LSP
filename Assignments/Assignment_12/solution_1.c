/**
 * @file solution_1.c
 * @author Shreyas Deshpande (shreyasdeshpande12@gmail.com)
 * @brief Write a program which is used to create unnamed pipe.
 *          Parent process creates new child process and both
 *          the processes will comunicate with each other.
 * @version 0.1
 * @date 2023-08-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>//For printf
#include<string.h>//for string length
#include <unistd.h> //for pipe system call
#include<stdlib.h>
#include<fcntl.h>

int main(void)
{
    /*
     *Un-named pipe has two ends, one is writing end ,
     * another is reading end.
     * as everything in Linux considered as file,
     * pipe is also considered as special type file.
     * To access each and of the piipe there are separate
     * file descriptors, and to store those file descriptors,
     * we use the array of an integer to hold both the file
     * descriptors. The Following array FD serves the same purpose.
     */
    int FD_1[2];
    int FD_2[2];
    int Ret = 0;
    
    // Buffer for data transfer
    char Buff[512] = {'\0'};

    // Create unnamed pipe
    pipe(FD_1);
    pipe(FD_2);

    Ret = fork();

    if (Ret == 0) // Child Process
    {
        printf("\nChild is talking...\n");
        close(FD_1[0]);
        write(FD_1[1],"Hi",2);

        printf("Child is listening...\n");

        memset(Buff,0,sizeof(Buff));
        close(FD_2[1]);
        read(FD_2[0],Buff,sizeof(Buff));

        printf("Parent Says: %s\n",Buff);

        exit(0);



    }
    else //Parent Process
    {
        printf("\nParent Listening...\n");
        memset(Buff,0,sizeof(Buff));
        close(FD_1[1]);
        read(FD_1[0],Buff,sizeof(Buff));
        printf("Child Says: %s\n",Buff);

        printf("Parent is talking...\n");
        close(FD_2[0]);
        write(FD_2[1],"Hay Child",9);

    }

    

    return 0;
}
