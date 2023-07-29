/*
 *   Write a program which ceates process as process 2 and process 3 and
 *   our parent process terminates till both the process terminates
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

    int Ret1 = 0, Ret2 = 0;
    int Exit_Status = 0, PID =0;


    Ret1 = fork();

    if (Ret1 == 0)
    {
        // process 2

        execl("./process_2", "NULL", NULL);
    }
    else
    {
        printf("This is parent process with PID %d and PPID %d\n", getpid(), getppid());
    }

    Ret2 = fork();

    if (Ret2 == 0)
    {
        execl("./process_3","NULL",NULL);
    }
    else{
         printf("This is parent process with PID %d and PPID %d\n", getpid(), getppid());
    }

    PID = waitpid(Ret2,&Exit_Status,0);

    printf("The last process terminated with PID %d\n",PID);

    return 0;
}
