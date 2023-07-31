/*
 *   Write a program which is used to print
 *   home directory and login username
 */

#include <stdio.h>
#include <string.h>

extern char **environ;

int main()
{
    char **env = environ;
   
    for (; *env != NULL; env++)
    {
        if (((strstr(*env, "LOGNAME")) != NULL) || ((strstr(*env, "HOME")) != NULL))
        {
            printf("%s\n", *env);
        }
    }

    return 0;
}
