/*Problem Statement:
*      Write a program which accepts two directory names from user
*      and move all file from source directory to destination directory.
*
*/

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc, char* argv[]){
    
    DIR *dp_s = NULL;
    DIR *dp_d = NULL;
    struct dirent *entry = NULL;

    char src_fname[30] ={'\0'};
    char dest_fname[30] = {'\0'};

    if(argc != 3){
        printf("Please enter the source and destination directory names\nas command line arguments\n");
        return -1;
    }

    dp_s = opendir(argv[1]);

    if(dp_s == NULL){
        printf("Can't open the Source directory\n");
        return -1;
    }

    dp_d = opendir(argv[2]);
    if(dp_d == NULL){
        printf("Can't open destination directory\n");
        return -1;
    }

    while((entry = readdir(dp_s)) != NULL){
        sprintf(src_fname,"%s/%s",argv[1],entry->d_name);
        sprintf(dest_fname,"%s/%s",argv[2],entry->d_name);

        rename(src_fname,dest_fname);
        unlink(src_fname);
    }

    closedir(dp_s);
    closedir(dp_d);

    
    return 0;
}
