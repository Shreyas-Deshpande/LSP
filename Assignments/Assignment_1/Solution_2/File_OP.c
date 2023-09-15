#include "File_OP.h"

/**
 * @brief Opens the file in given mode
 *
 * @param Name
 *          Name of the file
 * @param Mode
 *          Mode in which you want to open the file
 * @return int
 *          -1 => Failed to open file in given mode
 *          File Descriptor no => if successfully opened the file
 */
int Open_File(char *Name, char *Mode)
{
    int fd = 0;

    if ((strcmp(Mode, "Read")))
    {
        fd = open(Name, O_RDONLY);
    }
    else if ((strcmp(Mode, "Write")))
    {
        fd = open(Name, O_WRONLY);
    }
    else if ((strcmp(Mode, "R/W")))
    {
        fd = open(Name, O_RDWR);
    }
    else if ((strcmp(Mode, "Append")))
    {
        fd = open(Name, O_RDWR | O_APPEND);
    }
    else
    {
        fd = open(Name, O_RDONLY);
    }

    if (fd == -1)
    {
        return -1;
    }

    return fd;
}

/**
 * @brief Close the file with given file descriptor
 *
 * @param fd
 *          File Descriptor of the file you want to close
 * @return int
 *         0 => success
 *         -1 => Failuer
 */
int Close_File(int fd)
{
    return (close(fd));
}
