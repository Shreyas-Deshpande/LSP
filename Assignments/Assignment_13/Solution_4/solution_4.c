/**
 * @file solution_4.c
 * @author Shreyas Deshpande (shreyasdeshpande@gmail.com)
 * @brief Write a program which accepts user defined signal
 * @version 0.1
 * @date 2023-09-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void signal_handler(int signal_NO){
    printf("Signal-%d received\n",signal_NO);
}

int main(){

    
    signal(SIGUSR1,signal_handler);
    signal(SIGUSR2,signal_handler);
    printf("The process is runnig and waiting for user defined signal\n");
    for(;;)
        pause();
    return 0;

}
