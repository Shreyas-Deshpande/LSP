/*
*Problem Statement:
*       Write a program which accept directory name from user and
*       print all file names from that directory.
*/

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc, char* argv[]){
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char fName[200]={'\0'};

    if(argc != 2){
        printf("Enter the directory name as command line argument\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL){
        printf("Can't Open the Directory\n");
        return -1;
    }

    printf("Entries from directory are:\n");

    while((entry = readdir(dp)) != NULL){
        sprintf(fName,"%s/%s",argv[1],entry->d_name);
        printf("%s\n",fName);
    }

    closedir(dp);

    return 0;
}
