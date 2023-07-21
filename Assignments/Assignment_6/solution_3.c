/*Problem Statement:
*   Write a program which accept directory name and file name from user 
*   and create file in that directory
*/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/dir.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    int fd = 0, fD = 0;
    char fName[30] = {'\0'};

    if(argc != 3){
        printf("Insufficient Arguments\n");
        return -1;
    }

    sprintf(fName,"%s/%s",argv[1],argv[2]);

    fD = mkdir(argv[1],0777);
    if(fD== -1){
        printf("Unable to create Drirectory\n");
        return -1;
    }

    fd = creat(fName,0777);
    if(fd == -1){
        printf("Unable to create file\n");
        return -1;
    }

    return 0;
}
