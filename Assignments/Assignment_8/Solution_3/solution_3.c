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
    int Ret1 = 0, Ret2 = 0, Ret3 = 0;

    Ret1 = fork();

    if(Ret1 == 0){
        execl("./Process_2","NULL",NULL);
    }
    else{
        printf("Parent process running with PID %d and PPID %d\n",getpid(),getppid());
    }

    Ret2 = fork();
    if(Ret2 == 0){
        execl("./Process_3","NULL",NULL);
    }
    else{
        printf("Parent process running with PID %d and PPID %d\n",getpid(),getppid());
    }

    Ret3 = fork();

    if(Ret3 == 0){
         execl("./Process_4","NULL",NULL);
    }
    else{
         printf("Parent process running with PID %d and PPID %d\n",getpid(),getppid());
    }


    return 0;
}
