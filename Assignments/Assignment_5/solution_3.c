/*Problem Statement:
*   Write a program which accepts the directory name from user
*   and write information of all regular files in it and then
*   read the contents from that file.
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/dir.h>

char* fName = "file_info.txt";
char buff[20];

struct fileInfo{
    char Name[30];
    int Size;
    unsigned int iNode;
    int Ref_Count;
};

int main(int argc, char* argv[]){
    int fd =0, iCount =0,i=0, Ret =0;
    struct stat obstat;
    struct dirent *entry;
    DIR *dp;
    struct fileInfo info, readInfo;
    
    

    if(argc != 2){
        printf("Insufficient Arguments\n");
        return -1;
    }

    dp = opendir(argv[1]);
    fd = open(fName,O_RDWR|O_APPEND);

    if(fd == -1){
        printf("Unable to Open file\n");
        return -1;
    }

    if(dp == NULL){
        printf("Unable to open folder\n");
        return -1;
    }

   while((entry = readdir(dp)) != NULL){
    sprintf(buff,"%s/%s",argv[1],entry->d_name);
    stat(buff,&obstat);

    if(S_ISREG(obstat.st_mode)){
        //printf("%s\n",buff);
        strcpy(info.Name,buff);
        info.iNode = obstat.st_ino;
        info.Size = obstat.st_size;
        info.Ref_Count = obstat.st_nlink;

        write(fd,&info,sizeof(info));
        iCount++;
    } 
     
   }
   close(fd);

    printf("closing directory %s\n",argv[1]);
    Ret = closedir(dp);

    if(Ret == -1){
        printf("can't close the directory\n");
    }


    printf("iCount: %d\n",iCount);

    //Now read the file info
    fd = open(fName,O_RDONLY);
    if(fd == -1){
        printf("Unable to open file\n");
        return -1;
    }

    for(i=0;i<iCount;i++){
        Ret = read(fd,&readInfo,sizeof(readInfo));
    
        printf("File Name: %s\n",readInfo.Name);
        printf("Size: %d\n",readInfo.Size);
        printf("iNode No: %d\n",readInfo.iNode);
        printf("Link Count: %d\n",readInfo.Ref_Count);

        lseek(fd,((sizeof(readInfo))*(i+1)),SEEK_SET);

    }

    close(fd);

    return 0;

}
