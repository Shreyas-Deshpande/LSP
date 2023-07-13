/*
*Problem Statement:
*   Write a program which accept file name and mode and that program check whether 
*our process can access that file  in accepted mode or not.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char* argv[]){
    
    struct stat statobj;
    
    if(argc != 3){
        printf("Please provide the file name and mode as command line arguments\n");
        return -1;
    }

    stat(argv[1],&statobj);

    if((statobj.st_mode&S_IRUSR) && !(strcmp(argv[2],"Read"))){
        printf("The file can be accessed in %s Mode\n", argv[2]);
    }
    else if((statobj.st_mode&S_IWUSR) && !(strcmp(argv[2],"Write"))){
        printf("The file can be accessed in %s Mode\n", argv[2]);
    }
    else if((statobj.st_mode&S_IRUSR) && (statobj.st_mode&S_IWUSR) &&  !(strcmp(argv[2],"Read/Write"))){
        printf("The file can be accessed in %s Mode\n", argv[2]);
    }

    else if((statobj.st_mode&S_IRUSR) && (statobj.st_mode&S_IWUSR) && strcmp(argv[2],"Append")){
        printf("The file can be accessed in %s Mode\n", argv[2]);
    }

    else{
        printf("The file don't have %s permission\n",argv[2]);
    }

    





    return 0;
}
