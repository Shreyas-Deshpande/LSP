/**
 * @file Child_process.c
 * @author Shreyas Deshpande (shreyasdeshpande12@gmail.com)
 * @brief This is child process which receives the signal from
 *          Parent process for communication.
 * @version 0.1
 * @date 2023-09-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo)
{
    printf("Signal %d Received\n", signo);
}

int main()
{

    signal(SIGINT, sig_handler);
    printf("Child Process is running\n");

    for (;;)
        pause();

    return 0;
}
