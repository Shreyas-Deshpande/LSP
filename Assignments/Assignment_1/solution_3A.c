/*
*Problem Statement:
*   Write a program which accept file name and mode and that program check whether 
*our process can access that file  in accepted mode or not.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[]){
    int mode =0;
    
    
    if(argc != 3){
        printf("Please provide the file name and mode as command line arguments\n");
        return -1;
    }

    if(!(strcmp(argv[2],"Read"))){
        mode = R_OK;
    }
    else if(!(strcmp(argv[2],"Write"))){
        mode = W_OK;
    }
    else if(!(strcmp(argv[2],"Execute"))){
        mode = X_OK;
    }

    if((access(argv[1],mode)) == -1){
        printf("File don't have %s permission\n",argv[2]);
        return -1;
    }
    else{
        printf("The file have %s permission\n",argv[2]);
    }
    return 0;
}
