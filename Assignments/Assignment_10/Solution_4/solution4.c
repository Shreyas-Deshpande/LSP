/**
 * @file solution4.c
 * @author Shreyas Deshpande
 * @brief Write a program which creates single thread and it accepts one value from
 *         user, and it return same value to caller thread.
 * @date 2023-08-02
 *
 */

#include <stdio.h>
#include <pthread.h>

void *ThreadCB(void *ptr)
{

    int iNo = 0;
    printf("Enter a number: ");
    scanf("%d", &iNo);

    pthread_exit(iNo);
}

int main()
{
    int Ret = -1, result = 0;
    pthread_t TID = 0;

    Ret = pthread_create(&TID,
                         NULL,
                         ThreadCB,
                         NULL);

    if (Ret != 0)
    {
        printf("Unable to create thread\n");
        return -1;
    }

    pthread_join(TID, &result);

    printf("The value returned from thread is: %d\n", result);

    pthread_exit(NULL);

    return 0;
}
