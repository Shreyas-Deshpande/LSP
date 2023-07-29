#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/dir.h>
#include<string.h>

#define DESKTOP "/home/shreyas/Desktop"
#define OP_FILE "Demo.txt"


int main()
{
    int fd = 0;
    DIR *dp = NULL;
    struct dirent *entrty = NULL;
    char fName[30] = {'\0'};

    fd = creat(OP_FILE,0744);
    if(fd == -1){
        printf("Unable to create file\n");
        return 0;
    }

    fd = open(OP_FILE,O_RDWR | O_APPEND);

    dp = opendir(DESKTOP);
    if(dp == NULL){
        printf("Unable to open directory\n");
        return -1;
    }

    while((entrty = readdir(dp)) != NULL){
        strcpy(fName,entrty->d_name);
        //write(0,fName,sizeof(fName));
        write(fd,fName,strlen(fName));
        memset(fName,0,sizeof(fName));
        write(fd,"\n",1);
    }

    close(fd);
    closedir(dp);

    return 0;

}
