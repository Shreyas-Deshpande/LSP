/**
 * @file Receiver.c
 * @author Shreyas Deshpande (shreyasdeshpande@gmail.com)
 * @brief This is a receiver process which accepts signal from sender process
 * @version 0.1
 * @date 2023-09-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int sig)
{
    printf("[Receiver Process]: Signal-%d received\n",sig);
}

int main()
{

    signal(SIGINT, signal_handler);
    for (;;)
        pause();
    return 0;
}
