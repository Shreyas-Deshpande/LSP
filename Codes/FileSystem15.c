#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[]){

    int fd_source = 0;
    int fd_dest = 0, Ret =0;
    char Buffer[BLOCKSIZE] = {'\0'};

    if(argc != 3){
        printf("Insufficient Arguments\n");
        return -1;
    }

    fd_source = open(argv[1],O_RDONLY);
    if(fd_source == -1){
        printf("Unable to Open Source file\n");
        return -1;
    }

    fd_dest = creat(argv[2],0777);
    if(fd_dest == -1){
        printf("Unable to create destination file\n");
        close(fd_source);
        return -1;
    }

    while((Ret = read(fd_source,Buffer,sizeof(Buffer))) != 0){
        write(fd_dest,Buffer,Ret);
        memset(Buffer,0,sizeof(Buffer));//Clear the Buffer before next read
    }

    close(fd_source);
    close(fd_dest);

    return 0;
}
