/*
*Write a program which is used to demonstrate the concept of I/O redirection
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){

    int result = 0, iNo1 = 0, iNo2 =0;

    scanf("%d",&iNo1);
    scanf("%d",&iNo2);

    result = iNo1 + iNo2;

    printf("Result = %d\n", result);

    return 0;
}

//Exewcution command
// ./solution_1 <Input.txt >Output.txt
