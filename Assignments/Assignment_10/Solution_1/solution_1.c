/*
 *   Write a program Which is used to create simple thread
 *   by using pthread library
 */

#include <stdio.h>
#include <pthread.h>

void *Thread1(void *ptr)
{
    /*Write Thread logic here*/
    printf("This is thread\n");

    /*Kill the thread*/
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID; // Variable to hold the Thread ID
    int Ret = 0;

    /* Create new thread */

    Ret = pthread_create(&TID,
                         NULL,
                         Thread1,
                         NULL);

    if (Ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    printf("Thread is created with ID: %lu\n", TID);

    /* Tell the main thread to wait until
     newly created thread ends */
    pthread_join(TID, NULL);

    /* Kill the main thread */
    pthread_exit(NULL);

    return 0;
}
