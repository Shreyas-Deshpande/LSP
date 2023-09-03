/**
 * @file solution_3.c
 * @author Shreyas Deshpande (shreyasdeshpande@gmail.com)
 * @brief Write a program which creates such a process,
 *        which accepts signals from the terminal
 * @version 0.1
 * @date 2023-09-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int main(){

    int ret =0;

    ret = fork();

    if(ret == 0){
        //child process
        execl("./child_proc","NULL",NULL);
    }
    else{
        printf("Parent process is running with child PID: %d\n",ret);
    }

    return 0;
}
