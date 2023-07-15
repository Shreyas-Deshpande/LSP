/*Problem Statement:
*       write a program which accepts two file namesfrom user and
*       copy the contents of existing file into newly created file.
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char* argv[]){
    int fdSource = 0, fddestination = 0, Ret = 0;
    char cBuff[BLOCKSIZE]={'\0'};

    if(argc != 3){
        printf("Please enter the source and destination file names \n as command line arguments\n");
        return -1;
    }

    fdSource = open(argv[1],O_RDONLY);
    if(fdSource == -1){
        printf("Can't open Source file\n");
        return -1;
    }

    fddestination = creat(argv[2],0777);
    if(fddestination == -1){
        printf("Can't create new file\n");
        return -1;
    }

    while((Ret = read(fdSource,cBuff,sizeof(cBuff))) != 0){
        write(fddestination,cBuff,Ret);
        memset(cBuff,0,sizeof(cBuff));
    }

    close(fdSource);
    close(fddestination);

    return 0;
}
