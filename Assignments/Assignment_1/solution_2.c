/*
*Problem Statement:
*   Write a program which accept file name and mode from user and open that file in specified mode.
*/

#include<stdio.h>// for printf
#include<fcntl.h>//for mode defination
#include<string.h> // for strcmp
#include<unistd.h> //For close

int main(int argc, char* argv[]){
    int fd =0;

    if(argc!=3){
        printf("Please provide Filename and mode as input arguments\n");
        return -1;
    }

    if((strcmp(argv[2],"Read"))){
       fd = open(argv[1],O_RDONLY);
    }
    else if((strcmp(argv[2],"Write"))){
        fd = open(argv[1],O_WRONLY);
    }
    else if((strcmp(argv[2],"Read/Write"))){
        fd = open(argv[1],O_RDWR);
    }
    else if((strcmp(argv[2],"Append"))){
        fd = open(argv[1],O_APPEND);
    }
    else{
        fd = open(argv[1],O_RDONLY);
    }

    
    if(fd == -1){
        printf("Can't open the file in specified mode\n");
        return -1;
    }
    else{
        printf("File gets opened succesfully\n");
        printf("File Descriptor: %i\n",fd);
        printf("Mode: %s\n",argv[2]);
    }

    close(fd);
    return 0;
}
