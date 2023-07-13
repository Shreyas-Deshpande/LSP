#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char *argv[]){
    struct stat sobj; //Object of stat structure

    if(argc!=2){
        printf("Insufficient Arguments\n");
        return -1;
    }

    stat(argv[1],&sobj);

    printf("File Name: %s\n", argv[1]);
    printf("File Size is: %d\n",sobj.st_size);
    printf("Number of Links: %d\n", sobj.st_nlink);
    printf("Inode Number: %d\n", sobj.st_ino);
    printf("File system number: %d\n",sobj.st_dev);
    printf("Number of Blocks: %d\n", sobj.st_blocks);

    return 0;
}
