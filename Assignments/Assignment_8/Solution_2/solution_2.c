/*
*   Write arprogram which create three level hirearchy,
*   where process 1 creates process 2 and it internally creates
*   proces 3.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[]){

    int Ret = 0;

    Ret = fork();

    if(Ret == 0){
        //Child process

        execl("./Child_Process_1","NULL",NULL);
    }
    else
    {
        printf("Parent process wit PID; %d & PPDI: %d\n",getpid(),getppid());
    }
    

    return 0;
}
