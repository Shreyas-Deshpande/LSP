/*
*   Write a program which is used to increase the priority of current process by 5
*/

#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

int main(){
    
    printf("Priority before increment is: %d\n",getpriority(PRIO_PROCESS,0));

    nice(-5); //Lower the number higher the priority

    printf("Priority after increment is: %d\n",getpriority(PRIO_PROCESS,0));

    return 0;
}
