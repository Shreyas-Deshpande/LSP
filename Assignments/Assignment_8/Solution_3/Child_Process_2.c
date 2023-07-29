#include<stdio.h>
#include<unistd.h>

int main(){
    
    printf("Child_Process-2:\tPID:%d\tPPID%d\n",getpid(),getppid());
    //printf("Process is runnig with PID: %d and PPID: %d\n",getpid(),getppid());

    return 0;
}
