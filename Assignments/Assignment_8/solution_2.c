/*
*   Write arprogram which create three level hirearchy,
*   where process 1 creates process 2 and it internally creates
*   proces 3.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char* argv[]){

    int Ret = 0, Ret1 = 0;

    Ret = fork(); //create process 2

    if(Ret == 0){
        //Process 2
        printf("This is process-2 with PID: %d\n",getpid());
        printf("Parent ID %d\n",getppid());

        Ret1 = fork(); //create process 3
        if(Ret1 == 0){
            printf("This is Process-3 with PID: %d\n",getpid());
            printf("Parent ID %d\n",getppid());
        }
    }
    else{
        //Process 1
        printf("This is Process-1 with PID: %d\n",getpid());
    }

    return 0;
}
