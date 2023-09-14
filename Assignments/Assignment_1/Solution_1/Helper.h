#include <stdio.h>  // For printf
#include <fcntl.h>  //for file mode definations(MACROS)
#include <unistd.h> //for close system call

int open_file(char *, int flag);

int close_file(int);
