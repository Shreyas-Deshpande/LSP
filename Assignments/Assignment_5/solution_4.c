/*Problem Staement:
*   write a program which accepts directory name from user and
*   combine all contetnts of the file  from that directory into 
*   one file named as AllCombine
*/  

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>
#include<sys/dir.h>
#include<sys/stat.h>

#define BLOCKSIZE 1024

int main(int argc, char* argv[]){

    int fd_d = 0, fd_s = 0, Ret = 0;
    char Buff[BLOCKSIZE] = {'\0'};
    char fName[30] = {'\0'};

    DIR *dp =NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    
    if(argc != 3){
        printf("Insufficient Arguments\n");
        return -1;
    }

   
    dp = opendir(argv[1]);
    if(dp == NULL){
        printf("Can't open directory\n");
        return -1;
    }

    

    fd_d = open(argv[2],O_RDWR|O_APPEND);
    if(fd_d == -1){
        printf("can't open %s file\n", argv[2]);
        return -1;
    }

    
    while((entry = readdir(dp)) != NULL){
        sprintf(fName,"%s/%s",argv[1],entry->d_name);

        stat(fName,&sobj);

        if(S_ISREG(sobj.st_mode)){
            fd_s = open(fName,O_RDONLY);
            if(fd_s == -1){
                printf("Can't open %s file\n",fName);
                return -1;
            }

            while((Ret = read(fd_s,Buff,sizeof(Buff))) != 0){
                write(fd_d,Buff,Ret);

                memset(Buff,0,sizeof(Buff));
        }

        close(fd_s);
        }
           
    }//End of directory traversing

    closedir(dp);
    close(fd_d);

    printf("\nDone!\n");

    
    return 0;
}
