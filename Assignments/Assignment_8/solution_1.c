/*
*   Write a program in which parent process 
*   waits till its child process terminates. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(int argc, char* argv[]){
    int Ret =0, status;
    Ret = fork();

    if(Ret == 0)
    {
        //Child process
        printf("This is child process with PID %d\n",getpid());
    }
    else{
        //Parent Process
        printf("This is parent Process with PID: %d\n",getpid());
        waitpid(Ret, &status,0);
        printf("Child process status %d\n",status);
     //   WIFEXITED(status);
       // printf("Child process status %d\n",status);
    }

    return 0;
}
