/*
*Problem Statement:
*       Write a program which accept directory name from user and
*       print all file names and  its types from that directory.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat statobj;
    char fName[256]={'\0'};
    int fSize = 0;
    
    if(argc != 2){
        printf("Please enter the directry name as command line argument\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL){
        printf("Can't open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL){
        
        sprintf(fName,"%s/%s",argv[1],(char*)entry->d_name);
        stat(fName,&statobj);
        
        if(S_ISREG(statobj.st_mode)){
           
            fSize = (int)statobj.st_size;
            printf("%s\t\t%i\n",fName,fSize);
        }
        

    }

    closedir(dp);

    return 0;
}
