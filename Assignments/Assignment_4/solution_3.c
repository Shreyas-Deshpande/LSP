/*Problem Staement:
*   Write a program which accept two file names from user and 
*   check whether contents of those files are same or not.
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

int main(int argc, char* argv[]){
    struct stat obstat1, obstat2;
    int fd1 =0, fd2 =0, ret =0;
    char buff1[BLOCKSIZE]={'\0'};
    char buff2[BLOCKSIZE]={'\0'};
    
    if(argc != 3){
        printf("Insufficient arguments\n");
        return -1;
    }

    fd1 = open(argv[1],O_RDONLY);
    if(fd1 == -1){
        printf("Can't open 1st file\n");
        return -1;
    }
    
    fd2 = open(argv[2],O_RDONLY);
    if(fd2 == -1){
        printf("Can't open 2nd file\n");
        return -1;
    }

    fstat(fd1,&obstat1);
    fstat(fd2,&obstat2);

    if((obstat1.st_size != obstat2.st_size)){
        printf("Files are not identical, as file size is not same\n");
        return -1;
    }

    while((ret = read(fd1,buff1,sizeof(buff1))) != 0){
        ret = read(fd2,buff2,sizeof(buff2));

        if((memcmp(buff1,buff2,ret)) != 0){
            printf("Files are not identical\n");
            break;
        }
    }

    if(ret == 0){
        printf("Files are identical\n");
    }



    
    return 0;
}
