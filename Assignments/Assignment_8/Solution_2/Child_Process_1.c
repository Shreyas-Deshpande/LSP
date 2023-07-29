#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){
    int Ret = 0;
    //printf("Child_Process-1:\tPID:%d\tPPID%d\n",getpid(),getppid());

    Ret = fork();

    if(Ret == 0){
        execl("./Child_Process_2","NULL",NULL);
    }
    else{
        printf("Process is runnig with PID: %d and PPID: %d\n",getpid(),getppid());
    }


    return 0;
}
