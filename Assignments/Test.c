#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[]){
   
   DIR *dp = NULL;
   struct dirent *entry = NULL;
   char fName[100] = {'\0'};

    if(argc != 2){
        printf("Insufficient Arguments\n");
        return -1;
    }

   dp = opendir(argv[1]);

   if(dp == NULL){
    printf("Unable to open directory\n");
    return -1;
   }

   printf("-----------------------------------\n");
   printf("Entries from directory file are: \n");
   printf("------------------------------------\n");
   printf("Inode Number \t\t File Name\n");

   while((entry = readdir(dp)) != NULL){
    printf("%20s : %d \n", entry->d_name, entry->d_ino);
    sprintf(fName,"%s/%s",argv[1],entry->d_name);
    printf("Full path: %s",fName);
   }

    


   closedir(dp);

    return 0;
}
