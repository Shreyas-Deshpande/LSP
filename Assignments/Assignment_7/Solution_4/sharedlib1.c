#include "sharedlib1.h"

void helper(int iNo)
{
    void *ptr1 = NULL;
    void (*fptr)(int);

    ptr1 = dlopen("/home/shreyas/Documents/LSP/Assignments/Assignment_7/Solution_4/Inner.so", RTLD_LAZY);

    if (ptr1 == NULL)
    {
        printf("Unable to load the nested library\n");
        return;
    }

    fptr = dlsym(ptr1, "factorial");
    if (fptr == NULL)
    {
        printf("Unable to fetch the inner function address\n");
        return;
    }

    fptr(iNo);

    return;
}
