/**
 * @file solution_1.c
 * @author Shreyas
 * @brief Write a program to create 4 number of threads
 *          and main thread will wait until all the threads gets terminate
 * @date 2023-08-02
 *
 */
#include <stdio.h>
#include <pthread.h>

//Function definations of thread callback fucntions

void *Thread_1(void *ptr1)
{
    printf("This is thread-1\n");

    pthread_exit(NULL);
}

void *Thread_2(void *ptr2)
{
    printf("This is thread-2\n");

    pthread_exit(NULL);
}

void *Thread_3(void *ptr3)
{
    printf("This is thread-3\n");

    pthread_exit(NULL);
}

void *Thread_4(void *ptr4)
{
    printf("This is thread-4\n");

    pthread_exit(NULL);
}


//Create array of function pointer to store addresses of all callback fucntions
void *(*fptr[4])(void *) = {Thread_1, Thread_2, Thread_3, Thread_4};

int main()
{
    int Ret[4] = {0};
    int i = 0;
    pthread_t PID[4] = {0};

    //for loop for cerating 4 threads

    for (i = 0; i < 4; i++)
    {
        Ret[i] = pthread_create(&PID[i], NULL, fptr[i], NULL);
        if (Ret[i] != 0)
        {
            printf("Unable to create thread-%d", i + 1);
            return -1;
        }
        pthread_join(PID[i], NULL); // tell main thread to wait until last thread gets terminated
    }

    pthread_exit(NULL);//Exit main thread
    return 0;
}
