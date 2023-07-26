/*
 *   Write a program which is used to create 2 shared libaraies
 *   and that libraries should be loaded at runtime.
 *   First library should contain the function to check whether input no is prime or not.
 *   Second library shou;ld containsfunction to check whether the input no is prefect or not.
 */

#include <stdio.h>
#include<stdlib.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{

    void *Ptr = NULL;
    void (*fptr)(int);

    if (argc != 2)
    {
        printf("Insufficient Arguemnts\n");
        return -1;
    }

    Ptr = dlopen("/home/shreyas/Documents/LSP/Assignments/Assignment_7/Solution_3/Prime.so", RTLD_LAZY);
    if (Ptr == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    fptr = dlsym(Ptr, "checkPrime");
    if (fptr == NULL)
    {
        printf("Unable to fetch the function address \n");
        return -1;
    }

     fptr((atoi(argv[1])));

    Ptr = dlopen("/home/shreyas/Documents/LSP/Assignments/Assignment_7/Solution_3/Perfect.so", RTLD_LAZY);
    if (Ptr == NULL)
    {
        printf("Unable to load the library\n");
        return -1;
    }

    fptr = dlsym(Ptr, "checkPerfect");
    if (fptr == NULL)
    {
        printf("Unable to fetch the function address \n");
        return -1;
    }

    fptr((atoi(argv[1])));

    return 0;
}
