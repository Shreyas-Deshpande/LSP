/*
*Problem Statement:
*   Write a program which accept file name from user and open that file.
*/


#include "Helper.h"

int main(int argc, char* argv[]){\
    int fd =0;

    if(argc!=2){
        printf("Please enter the file name as command line argument\n");
        return -1;
    }



    fd = open_file(argv[1],O_RDONLY);

    if(fd == -1){
        printf("Can't Open File\n");
        return -1;
    }
    else{
        printf("File gets opened succesfully\n");
        printf("File Descriptor: %i\n",fd);
    }

    close_file(fd);
    return 0;
    
}
