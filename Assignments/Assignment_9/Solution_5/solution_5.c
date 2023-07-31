/*
*   Write a program which is used to yield our processor
*   using appropriate system call
*/

#include<stdio.h>
#include<sched.h>

int main(){
    int Ret = -1;

    Ret = sched_yield();

    if(Ret == 0){
        printf("CPU yield succesful\n");
    }

    return 0;
}
