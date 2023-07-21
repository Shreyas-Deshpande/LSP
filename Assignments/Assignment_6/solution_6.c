/*Problem Staement:
*   Write a program which accept directory name from user and
*   creat a hole in file if size is less than 1KB and if size is greater than 1KB 
*   then truncate the remaining data
*/

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/dir.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[]){
    
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char fName[30] = {'\0'};
    
    if(argc != 2){
        printf("Insufficient Arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL){
        printf("Unable to open the directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL){
        sprintf(fName,"%s/%s",argv[1],entry->d_name);

        stat(fName,&sobj);

        if(S_ISREG(sobj.st_mode)){
           truncate(fName,BLOCKSIZE);
        }
    }

    return 0;
}
