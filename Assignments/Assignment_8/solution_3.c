/*
 *   Write a progrma which creates three different processes
 *   internally as process 2, process 3 and process 4
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/wait.h>

int main()
{
    int Ret = 0;
    int status = 0, i= 0;



    for(i=0;i<3;i++){
        Ret = fork();
        if(Ret == 0){
            printf("Process %d: \tPID: %d \t PPID: %d\n", (i+1), getpid(), getppid());
            return 0;
        }
        else{
            printf("This is main porcess. PID: %d\n",getpid());
        }
    }


    waitpid(Ret,&status,0);

    return 0;
}
