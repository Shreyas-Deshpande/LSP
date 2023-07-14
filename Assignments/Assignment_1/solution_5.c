/*
*Problem Statement:
*   Write a program which accept file name and number of bytes from user 
*   and read that number of bytes from file.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>


int main(int argc, char* argv[]){
    int fd = 0;
    char* fBuff;


    if(argc != 3){
        printf("Please enter the filename and number of bytes to read\n in command line argument\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);
    if(fd == -1){
        printf("File can't open\n");
        return -1;
    }

    fBuff = (char*)malloc((atoi(argv[2]))*sizeof(char));

    if(read(fd,fBuff,(size_t)(atoi(argv[2])))){
        printf("File gets read succesfully & file contents are:\n\n");

        printf("%s\n",fBuff);
    }
    else{
        printf("Can't read the file\n");
    }

    free(fBuff);
    close(fd);

    return 0;
}
