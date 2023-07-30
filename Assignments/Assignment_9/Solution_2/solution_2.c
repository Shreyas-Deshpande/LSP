/*
* Write a program which creates 2 processes
*   Process-1 counts the number of capital characters from 'Demo.txt'
*   Process-2 counts the number of capital characters from 'Hello.txt'
*   Both the process write their counts in 'Count.txt' file
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{

    int Ret1 = 0, Ret2 = 0;
    int status1, status2, pid1, pid2;

    Ret1 = fork();

    if (Ret1 == 0)
    {
        execl("./Process_1", "NULL", NULL);
    }

    Ret2 = fork();

    if (Ret2 == 0)
    {
        execl("./Process_2", "NULL", NULL);
    }

    pid1 = wait(&status1);
    pid2 = wait(&status2);

    return 0;
}
