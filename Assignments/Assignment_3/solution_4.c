/*Problem Statement:
*   Write a program which accepts directory name from user and 
*   delete all empty files from directory
*/

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char* argv[]){
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat obstat;
    char fName[30] = {'\0'};

    if(argc != 2){
        printf("Enter the directory name as command line argument\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL){
        printf("Can't open the directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL){
        
        sprintf(fName,"%s/%s",argv[1],entry->d_name);

        stat(fName,&obstat);

        if(obstat.st_size == 0){
            printf("%s file is empty, and will delete now\n",fName);
            unlink(fName);
        }

    }
    
    return 0;
}




