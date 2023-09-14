#include "Helper.h"

int open_file(char *fName, int flag)
{
    int fd = 0;

    fd = open(fName, flag);

    if (fd == -1)
    {
        return -1;
    }

    return fd;
}

int close_file(int fd)
{
    return (close(fd));
}
