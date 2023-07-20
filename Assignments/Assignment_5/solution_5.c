/*Problem Statement:
*   Write a program which accepts the filename which contains the data 
*   of all files. We have create all files again.
*/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>

#define BLOCKSIZE 1024

struct fileInfo{
    char Name[30];
    int Size;
    unsigned int iNode;
    int Ref_Count;
};

int main(int argc, char* argv[]){

    int fd_info = 0, fd_data = 0,fd_new = 0, i = 5, Ret = 0, j = 0;
    char Buff[BLOCKSIZE] = {'\0'};
    char fName[30] = {'\0'};
    int seek_size = 0;

    struct fileInfo info;
    
    if(argc != 3){
        printf("Insufficent Arguments\n");
        return -1;
    }

    fd_info = open(argv[1],O_RDONLY);
    fd_data = open(argv[2],O_RDONLY);

    if((fd_data == -1) || (fd_info == -1)){
        printf("Unable to open the file\n");
        return -1;
    }

    while((Ret = read(fd_info,&info,sizeof(info))) != 0){

        printf("File Name: %s\n",info.Name);
        printf("File Size: %d\n",info.Size);

        //following while loop is for removing the Directory name before filename (Demo/)
        i=5; //Length of "Demo/" is 5
        while(info.Name[i] != '\0'){
            fName[(i-5)] = info.Name[i];
            i++;
        }
        printf("New File Name: %s\n\n",fName);
    
        //Create new file 
        fd_new = creat(fName,0744);
        if(fd_new == -1){
            printf("Unable to create new file\n");
            return -1;
        }


        read(fd_data,Buff,info.Size);
        write(fd_new,Buff,info.Size);

        printf("\n\n%s\n\n",Buff);
        seek_size += info.Size;
        lseek(fd_data,seek_size,SEEK_SET);


        close(fd_new);
        memset(fName,0,sizeof(fName));
        memset(Buff,0,sizeof(Buff));

    }    



    
    
    return 0;
}
