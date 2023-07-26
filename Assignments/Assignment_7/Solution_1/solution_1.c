/*Problrm Staement:
*   Write a program which is used to create shared library and 
*   that library should be loaded at runtime by another program.
*   That Library should contain,functions to perform arithmatic operations
*   like Addition, Subtraction, Multiplication and Division
*/

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>
#include<string.h>

int main(int argc, char* argv[]){
    
    void* ptr = NULL;
    void (*fptr)(int,int);
    

    if(argc != 4){
        printf("Insufficient Arguments\n");
        return -1;
    }

    /* Need to give the absolute path of dynamic library, relative path will not work*/
    ptr = dlopen("/home/shreyas//Documents/LSP/Assignments/Assignment_7/Solution_1/mathlib.so",RTLD_LAZY);
    if(ptr == NULL)
    {
        printf("Unable to load library\n");
        return -1;
    }

    if((strcmp(argv[1],"Add")) == 0){
        fptr = dlsym(ptr,"Add");
        if(fptr == NULL){
            printf("Unable to load the address of function\n");
            return -1;
        }
        
    }
    else if((strcmp(argv[1],"Subtract")) == 0){
        fptr = dlsym(ptr,"Sub");
        if(ptr == NULL){
            printf("Unable to load the address of function\n");
            return -1;
        }
    }
    else if((strcmp(argv[1],"Multiply")) == 0){
        fptr = dlsym(ptr,"Mul");
        if(ptr == NULL){
            printf("Unable to load the address of function\n");
            return -1;
        }
    }
    else if((strcmp(argv[1],"Divide")) == 0){
        fptr = dlsym(ptr,"Div");
        if(ptr == NULL){
            printf("Unable to load the address of function\n");
            return -1;
        }
    }

    fptr((atoi(argv[2])), (atoi(argv[3])));

    
    return 0;
}
