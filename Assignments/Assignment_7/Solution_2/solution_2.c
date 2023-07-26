/*
*   Write a program which used to create shared library and that library
*   should be loaded at runtime.
*   That library should contain a function which accepts 2 filenames 
*   from user and it will compare the contents of both files.
*/

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main(int argc, char* argv[]){

    void* ptr = NULL;
    void (*fptr)(char*,char*);

    ptr = dlopen("/home/shreyas/Documents/LSP/Assignments/Assignment_7/Solution_2/compareFile.so",RTLD_LAZY);

    if(ptr == NULL){
        printf("Can't open shared Library\n");
        return -1;
    }

    fptr = dlsym(ptr,"filecmp");
    if(fptr == NULL){
        printf("Unable to feth the address of the function\n");
        return -1;
    }

    fptr(argv[1],argv[2]);
    
    if(argc != 3){
        printf("Insufficient Arguments\n");
        return -1;
    }


    return 0;
}
