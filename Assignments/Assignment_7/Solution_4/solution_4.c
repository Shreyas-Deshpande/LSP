/*
 *
 *
 */

#include <stdio.h>
#include<stdlib.h>
#include <dlfcn.h>

int main(int argc, char *argv[])
{

    void *ptr = NULL;
    void (*fptr)(int);

    if (argc != 2)
    {
        printf("Insufficient Arguments\n");
        return -1;
    }

    ptr = dlopen("/home/shreyas/Documents/LSP/Assignments/Assignment_7/Solution_4/Outer.so",RTLD_LAZY);
    if(ptr == NULL){
        printf("Unable to load outer library\n");
        return -1;
    }

    fptr = dlsym(ptr,"helper");
    if(fptr == NULL){
        printf("Unable to fetch the helper function address\n");
        return -1;
    }

    fptr((atoi(argv[1])));

    return 0;
}
