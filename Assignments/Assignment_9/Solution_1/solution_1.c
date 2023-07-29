#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int Ret = 0;
    
    Ret = fork();

    if(Ret == 0){
        execl("./process","NULL",NULL);
    }
    else{
        printf("Parent process with PID %d and PPID %d\n",getpid(),getppid());
    }

    return 0;
}
