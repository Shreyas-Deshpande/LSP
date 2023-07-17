/*Problem Statement:
*   Write a program which accepts directory name from user
*   and copy first 10 bytes from all regular files into newly created 
*   file named as Demo.txt
*/
#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/dir.h>

int main(int argc, char* argv[]){

    struct stat obstat;
    struct dirent *entry = NULL;
    DIR *dp = NULL;
    int fd_s = 0, fd_d =0, ret =0;
    char fName[30]={'\0'}, rName[30]={'\0'}, temp_buff[10]={'\0'};

    if(argc != 2){
        printf("Insufficient arguments\n");
        return -1;
    }



    dp = opendir(argv[1]);

    sprintf(fName,"%s/%s",argv[1],"Demo.txt");

    fd_d = creat(fName,0744);

    if(fd_d == -1){
        printf("Can't create Demo.txt\n");
        return -1;
    }

    
    while((entry = readdir(dp)) != NULL){
        sprintf(rName,"%s/%s",argv[1],entry->d_name);
        stat(rName,&obstat);

        if(S_ISREG(obstat.st_mode)){

           // printf("%s\n",rName);
            
            fd_s = open(rName,O_RDONLY);
            ret = read(fd_s,temp_buff,10);

            if(ret !=0){ //Ommit the empty files including Demo.txt
                fd_d =open(fName,O_RDWR | O_APPEND);
                write(fd_d,temp_buff,sizeof(temp_buff));
                close(fd_d);
                close(fd_s);

            }
            
            
            
        }
        
    }

    closedir(dp);

    return 0;

}
