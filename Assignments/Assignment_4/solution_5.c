/*
*   Write a program which aceepts the filename and position from user and 
*   read 20 bytes from that position.
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char* argv[]){
    int fd = 0, Ret = 0;
    char buff[20]={'\0'};

    if(argc != 3){
        printf("Insuficient arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    lseek(fd,(atoi(argv[2])),SEEK_SET);

    Ret = read(fd,buff,sizeof(buff));

    printf("The read bytes are: \n%s\n",buff);

    close(fd);

    return 0;
}
