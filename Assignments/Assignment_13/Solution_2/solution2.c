/**
 * @file solution2.c
 * @author Shreyas Deshpande (shreyasdeshpande12@gmail.com)
 * @brief Write a program which creates child process and
 *        parent process will communicate with child process
 *        by sending signal.
 * @version 0.1
 * @date 2023-09-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int ret = 0;

    ret = fork();

    if (ret == 0)
    {
        // child process
        execl("./child_proc", "NULL", NULL);
    }
    else
    {
        // Parent Process
        printf("Parent is running\n");
        printf("Child Process ID: %d\n", ret);
        printf("Sending signal to child process %d\n", ret);
        sleep(2);
        kill(ret, SIGINT);
    }
    return 0;
}
