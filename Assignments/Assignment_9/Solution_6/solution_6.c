/*
*   Write a program which is used to display 
*   Environment of current process
*/

#include<stdio.h>

extern char **environ;

int main()
{
    char **env = environ;
    printf("Environment of current process is:\n\n");

    for(;*env != NULL;env++){
        printf("%s\n",*env);
    }
    
    return 0;
}
