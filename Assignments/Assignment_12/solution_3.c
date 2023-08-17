/**
 * @file solution_3.c
 * @author Shreyas Deshpande (Shreyasdeshpande12@gmail.com)
 * @brief Write a program which createss one child process,
 *          child process writes something in unnamed pipe,
 *          and parent process read the data from that pipe.
 * @version 0.1
 * @date 2023-08-17
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include<string.h>
#include <sys/stat.h>

char* Data = "This is data in un-named pipe";

int main()
{

    int Ret = 0;
    int FD[2];
    char Buffer[100];

    pipe(FD);
    Ret = fork();

    if (Ret == 0)
    {
        close(FD[0]);
        write(FD[1],Data,strlen(Data));

        exit(0);
        
    }
    else
    {
        close(FD[1]);
        read(FD[0],Buffer,sizeof(Buffer));
        printf("Data from child process: %s\n",Buffer);
        
        //close(FD[0]);
    }

    return 0;
}
