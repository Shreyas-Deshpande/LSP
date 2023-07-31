/*
 *   Write a program which is used to print
 *   home directory and login username
 */

#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>

extern char **environ;

int main()
{
    char **env = environ;
   
    printf("Login Name: %s\n",getlogin()); //Print Login Nmae
    printf("Login Name: %s\n",getenv("LOGNAME")); // another way to print login Name
    printf("Home Directory: %s\n",getenv("HOME")); // print Home directory
    

    return 0;
}
