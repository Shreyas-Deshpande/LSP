/*
 *   Write a program to create deamon process.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    pid_t PID = 0;
    pid_t SID = 0;

    /*Create Child Process*/

    PID = fork();

    if (PID < 0)
    {
        printf("Failed to create child process\n");
        return -1;
    }

    /* Kill the Parent process*/

    if (PID > 0)
    {
        printf("This is parent Process with PID %d\n", getpid());

        exit(0); // return success in exit status
    }

    /*Unmask the file mode*/
    umask(0);

    /* Set new session */

    SID = setsid();
    if (SID == -1)
    {
        printf("can't create new session\n");
        exit(1);
    }

    /* Change the current working directory to root */

    chdir("/");

    /*
        Close the standerd Input, Outputand Error devices
        i.e.
        stdin fd = 0
        stdout fd = 1
        stderr fd = 2
    */

    close(STDIN_FILENO);  /*close(0)*/
    close(STDOUT_FILENO); /*close(1)*/
    close(STDERR_FILENO); /*close(2)*/

    /*
        Open a log file in write mode
    */

    fp = fopen("Log.txt", "w+");

    /*
     The while loop bellow will contain the
     main logic of the deamon process, which
     performs some task for which deamon process
     is created.
    */

    while (1)
    {
        /* Giive some time for context switch*/

        sleep(1);
        fprintf(fp, "Logging info\n");
        fflush(fp);

        /*

         Core logic here


        */
    }
    fclose(fp);
    return 0;
}


/*Compilation procidure for deamon process
    1. gcc -Wall deamon.c -o deamon
    2. sudo ./deamon

    to verify that deamon process is running
    check the Log.txt file in root directory
*/
