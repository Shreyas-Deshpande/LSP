/**
 * @file Sender.c
 * @author Shreyas Deshpande (shreyasdeshpande@gmail.com)
 * @brief This is sender process which sends signal to
 * @version 0.1
 * @date 2023-09-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

int main(int argc, char *argv[])
{

    int PID = 0;

    if (argc != 1)
    {
        printf("[Sender Process]: Insufficiesnt Arguments\n");
        return -1;
    }
    sleep(2);
    PID = atoi(argv[0]);
    printf("[Sender Process]: Sending SIGINT to receiver process\n");
    kill(PID, SIGINT);
    sleep(1);
    printf("[Sender Process]: Sending SIGKILL to receiver process\n");
    kill(PID,SIGKILL);

    return 0;
}
