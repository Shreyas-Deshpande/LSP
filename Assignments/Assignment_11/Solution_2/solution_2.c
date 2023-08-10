/**
 * @file solution_2.c
 * @author Shreyas
 * @brief Write a program which creates multiple threads
 *          and sets its thread attributes accordingly.
 * @version 0.1
 * @date 2023-08-05
 *
 * @copyright Copyright (c) 2023
 *
 */

#define _GNU_SOURCE /* To get pthread_getattr_np() declaration */
#include <stdio.h>
#include <pthread.h>
#include <err.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

void *Threadproc(void *PTR)
{
    printf("This is thread with SYSTEM scope\n");

    pthread_exit(NULL);
}

int main()
{
    int Ret = 0;
    pthread_t TID = 0;
    pthread_attr_t objattr;
    pthread_attr_t *pattr = &objattr;

    pthread_attr_init(pattr);

    /*Change the thread scope to system*/
    pthread_attr_setscope(pattr, PTHREAD_SCOPE_SYSTEM);

    Ret = pthread_create(&TID, pattr, Threadproc, NULL);

    if (Ret != 0)
    {
        printf("Unable to create thread\n");
    }

    pthread_join(TID, NULL);
    printf("End of main thread\n");

    pthread_exit(NULL);

    return 0;
}
