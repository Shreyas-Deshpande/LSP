/*
*   Write a program which ceates process as process 2 and process 3 and  
*   our parent process terminates till both the process terminates
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

    int Ret = 0, status;

    Ret = fork();

    if(Ret == 0){
        //process 2
        printf("Process-2: \t PID: %d \t PPID: %d\n",getpid(),getppid());
        return 0;
    }
    else{
        //process 1
        printf("This is Parent process. PID: %d\n",getpid());

        printf("Child Process ID: %d\n",Ret);
        printf("Last process ended: %d\n",wait(&status));
    }

    Ret = fork();
    if(Ret == 0){
        //process 3
        printf("Process-3: \t PID: %d \t PPID: %d\n",getpid(),getppid());
        return 0;
    }
    else
    {
        //process 1
        printf("This is Parent process. PID: %d\n",getpid());

        printf("Child Process ID: %d\n",Ret);
        printf("Last process ended: %d\n",wait(&status));
    }

    

    return 0;
}
