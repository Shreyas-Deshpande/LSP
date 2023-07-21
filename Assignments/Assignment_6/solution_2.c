/*
*   Write a program which creates hole of size 1KB at the end of the file.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc, char* argv[]){
    
    int fd = 0, Ret = 0;
    char Buff[BLOCKSIZE] = {'\0'};

    if(argc != 2){
        printf("Insufficient Arguments\n");
        return -1;
    }

    fd = open(argv[1],O_RDWR|O_APPEND);
    if(fd == -1){
        printf("Can't open the file\n");
        return fd;
    }

    lseek(fd,0,SEEK_END);
    /*
    The hoel at end can be achieved using trucate system call as shown bellow

        ftruncate(fd,(file_Size+BLOCKSIZE));

        for this we need to create stat structure object to fetch the file_size
    */

   Ret = write(fd,Buff,sizeof(Buff));

   if(Ret == BLOCKSIZE){
    printf("Hole is succesfully created at the end of the file\n");
   }

    close(fd);

    return 0;
}
