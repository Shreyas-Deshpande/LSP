/*
 *Problem Statement:
 *   Write a program which accept file name and mode from user and open that file in specified mode.
 */
#include "File_OP.h"

int main(int argc, char *argv[])
{
    int fd = 0;

    if (argc != 3)
    {
        printf("Please provide Filename and mode as input arguments\n");
        return -1;
    }

    fd = Open_File(argv[1], argv[2]);

    if (fd == -1)
    {
        printf("Can't open the file in specified mode\n");
        return -1;
    }
    else
    {
        printf("File gets opened succesfully\n");
        printf("File Descriptor: %i\n", fd);
        printf("Mode: %s\n", argv[2]);
    }

    Close_File(fd);
    return 0;
}
