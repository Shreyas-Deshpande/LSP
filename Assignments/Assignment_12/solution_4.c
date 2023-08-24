/**
 * @file solution_4.c
 * @author Shreyas Deshpande (shreyasdeshpande12@gmail.com)
 * @brief   Write a program which map any file in memory,
 *          and read the data from that mapped file.
 * @version 0.1
 * @date 2023-08-18
 *
 * @copyright Copyright (c) 2023
 *
 */

/*USE the Mapped_File.txt for file mapping*/

/*mmap function prototype
    void *mmap(void *addr,
                size_t length,
                int prot,
                int flags,
                int fd,
                off_t offset);

    void* addr:
        Address of the memory region which is used to copy
        the contents of mapped file from disk.
        Most probrbly we should set this value to NULL,
        so the system(Kernel) will descide the appropriate
        address for the memory region.

    size_t length:
        This parameter specifies the length of the region,
        must be greater than 0.

    int prot:
        It defines the desired memory protection for the region.
        it can be single or ORed with any combination from following options
            -PROT_NONE
            -PROT_READ
            -PROT_WRITE
            -PROT_NONE

    int flags:
        The flags argument determines whether updates to the mapping are
       visible to other processes mapping the same region, and whether
       updates are carried through to the underlying file.
       The possible options are,
            -MAP_SHARED
            -MAP_SHARED_VALIDATE
            -MAP_PRIVATE
            -MAP_ANONYMOUS
            -MAP_FIXED
            etc.
        for all the flag options please reffer the man7 page

    int fd:
        File Descriptor of the file which has to be mapped
        over the memory region.

    int offset:
        Contents of file mapping are initialized using
        size_t length bytes starting at offset defined by this
        parameter.

*/

#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/*Following is function like macro
  which is used to print the error
  message.
*/

#define handle_error(msg)   \
    do                      \
    {                       \
        perror(msg);        \
        exit(EXIT_FAILURE); \
    } while (0)

int main(int argc, char *argv[])
{
    int fd = 0, i=0;
    /*
    following is a character pointer which
    holds the starting address of the
    region over which, the file is mappped.
    */
    char *addr = NULL;
    off_t pa_offset, offset = 0;
    int length = 15;

    if (argc != 2)
    {
        printf("Insfficient Arguments\n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);

    if (fd == -1)
    {
        handle_error("open");
    }

    /*mmap function requires page aligned offset
        the following instruction calculates the page
        alligned offset. offset variable contains user
        defined offset, for this example,
        offset is 0.*/

    pa_offset = offset & ~(sysconf(_SC_PAGE_SIZE) - 1);

    addr = mmap(NULL,length,PROT_READ,MAP_SHARED,fd,pa_offset);

    if(addr == MAP_FAILED){
        handle_error("mmap");
    }

    printf("Mapped file contents are:\n");
    for(i=0;i<length;i++){
        printf("%c",addr[i]);
    }

    printf("\n\nFile reading Completed\n");

    return 0;
}
