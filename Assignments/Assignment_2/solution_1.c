/*
*Problem Statement:
*   Write a program which accepts filename from user and read whole file.
*
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>

struct stat obstat;

int main(int argc, char* argv[]){
    int fd = 0, Size = 0;
    char* fBuff;
        
    if(argc != 2){
        printf("Enter the filename as command line argument\n");
        return -1;
    }
    
    fd = open(argv[1],O_RDONLY);

    if(fd == -1){
        printf("Can't open the file\n");
        return -1;
    }

    stat(argv[1],&obstat);

    Size = (int)obstat.st_size;

    fBuff = (char*)malloc(Size*sizeof(char));

    if(read(fd,fBuff,Size)){
        printf("File Read Successfully\n The File Contents are:\n\n");
        printf("%s\n",fBuff);
    }
    else{
        printf("Can't read the file\n");
    }

    free(fBuff);
    close(fd);

    return 0;
}
