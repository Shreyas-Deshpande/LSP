#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(){
    
    printf("Process 3: PID: %d PPID: %d \n",getpid(),getppid());

    return 0;
    
}
