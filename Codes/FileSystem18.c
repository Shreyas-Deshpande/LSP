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

    if(S_ISREG(sobj.st_mode)){
        printf("It's a regular File\n");
    }
    else if(S_ISDIR(sobj.st_mode)){
        printf("It's a directory\n");

    }
    else if(S_ISLNK(sobj.st_mode)){
        printf("It's a symbolic Link\n");
    }
   
    return 0;
}
