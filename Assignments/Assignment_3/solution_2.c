/*Problem Statement:
*       Write a program which accepts one directory name and file name from user
*       and check whether that file is present in that folder or not.
*
*/

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>



int main(int argc, char* argv[]){
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char fName[30]={'\0'};

    if(argc != 3){
        printf("please enter the directory name and file name as command line argument\n");
        return -1;
    }

    dp = opendir(argv[1]);

    if(dp == NULL){
        printf("Can't open the directory\n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        if(!(strcmp(entry->d_name,argv[2]))){
            printf("The given file is present in the directory\n");
            break;
        }
        
    }

    if(entry ==  NULL){
        printf("The given file is not present in the directory\n");
    }
    
    closedir(dp);

    return 0;
}
