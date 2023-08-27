#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main(){
    void* ptr = NULL;
    void (*fptr)(); //Function pointer

    ptr = dlopen("/home/shreyas/Documents/LSP/Dynamic_Library/library.so",RTLD_LAZY); //Give absolute path of .so file
    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    fptr = dlsym(ptr,"Display");
    if(ptr == NULL)
    {
        printf("Unable to load the address of function\n");
        return -1;
    }

    fptr();

    return 0;
}


//gcc -rdynamic -o client client.c
// ./client
