/*
*   Write a program which accepts filename from user and write string in that file
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[]){
    int fd = 0, Ret = 0;

    if(argc != 3){
        printf("Please enter the filename and String to add in the file \nas command line argument\n");
        return -1;               
    }

    fd = open(argv[1],O_RDWR);

    if(fd == -1){
        printf("Can't open the file\n");
        return -1;
    }

    //printf("%s\t%li\n",argv[2],(strlen(argv[2])));

    
    if(write(fd,argv[2],(strlen(argv[2])))){
        printf("String written in file succesfully\n");
    }
    else{
        printf("Can't write into the file\n");
    }

    close(fd);
    return 0;
}
