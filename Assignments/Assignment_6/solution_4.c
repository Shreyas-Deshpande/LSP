/*Problem Staement:
*   Write a program which accepts directory name from user and 
*   delete all such files whos size is greater than 100 Bytes.
*/

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/dir.h>

int main(int argc, char* argv[]){
    
    struct stat sobj;
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char fName[30] = {'\0'};

    if(argc != 2){
            printf("Insufficient Arguments\n");
            return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL){
        printf("Can't open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL){
        sprintf(fName,"%s/%s",argv[1],entry->d_name);

        stat(fName,&sobj);

        if(S_ISREG(sobj.st_mode) && (sobj.st_size > 100)){
            unlink(fName);
        }

    }
    
    return 0;
}
