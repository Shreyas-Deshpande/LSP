/**
 * @file child_process.c
 * @author Shreyas Deshpande (shreyasdeshpande12@gmail.com)
 * @brief This is child process which accepts signal from terminal
 * @version 0.1
 * @date 2023-09-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include <signal.h>

void signal_handler(int sigNo)
{
    switch (sigNo)
    {
    case 1:
        printf("SIGHUP: \t %d\n", sigNo);
        break;

    case 2:
        printf("SIGINIT: \t %d\n", sigNo);
        break;

    case 3:
        printf("SIGQUIT: \t %d\n", sigNo);
        break;

    case 4:
        printf("SIGILL: \t %d\n", sigNo);
        break;

    case 5:
        printf("SIGTRAP: \t %d\n", sigNo);
        break;

    case 6:
        printf("SIGABRT: \t %d\n", sigNo);
        break;

    case 7:
        printf("SIGBUS: \t %d\n", sigNo);
        break;

    case 9:
        printf("SIGKILL: \t %d\n", sigNo);
        break;

    case 10:
        printf("SIGUSR1: \t %d\n", sigNo);
        break;

    case 12:
        printf("SIGUSR2: \t %d\n", sigNo);
        break;

    default:
        printf("Signal %d arrived\n", sigNo);
        break;
    }
    return;
}

int main()
{

    printf("Child Process is Running now.\n");

    signal(SIGINT, signal_handler);

    for (;;)
        pause();
    return 0;
}
