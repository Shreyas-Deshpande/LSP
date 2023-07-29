#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int Ret = 0;
    printf("Child_Process-3:\tPID:%d\tPPID%d\n",getpid(),getppid());

    return 0;
}
