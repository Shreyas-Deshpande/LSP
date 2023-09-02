#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char *path_fifo = "/tmp/mypipe";
    char Buffer[100];

    printf("Client is running for reading data from named pipe\n");

    fd = open(path_fifo, O_RDONLY);
    if (fd == -1)
    {
        printf("Unable to open named pipe for reading\n");
        return -1;
    }

    read(fd, Buffer, 20);

    printf("Daata read from named pipe is:\n%s\n", Buffer);

    return 0;
}
