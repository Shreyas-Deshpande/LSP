#include<stdio.h>
#include<unistd.h>

int main(){
    
    printf("Child_Process-1:\tPID:%d\tPPID%d\n",getpid(),getppid());

    return 0;
}
