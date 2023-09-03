/**
 * @file solution_5.c
 * @author Shreyas Deshpande (shreyasdeshpande12@gmail.com)
 * @brief  Write a program which ceates two processes,
 *          as sender and receiver, in which sender process
 *          sends signal to receiver process.
 * @version 0.1
 * @date 2023-09-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{
    int Ret1 = 0, ret2 = 0;
    char pNO[8]={'\0'};

    Ret1 = fork();

    if (Ret1 == 0)
    {
        execl("./Receiver", "NULL", NULL);
    }

    sprintf(pNO,"%d",Ret1);
    printf("PID of Receiver is %s\n",pNO);

    ret2 = fork();

    if (ret2 == 0)
    {
        execl("./Sender", pNO, NULL);
    }

    return 0;
}
