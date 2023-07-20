/*Problem Statement:
*   Write a program which accepts the file name which contains
*   information of all files,we have to print all file names
*   whose size is greater than 10 bytes.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>



struct fileInfo{
    char Name[30];
    int Size;
    unsigned int iNode;
    int Ref_Count;
};

int main(int argc, char* argv[]){
    int fd = 0, Ret = 0, i = 5;
    struct fileInfo info;
    char fName[30] = {'\0'};

    if(argc != 2){
        printf("insufficien arguments\n");
        return 0;
    }


    fd = open(argv[1],O_RDONLY);
    if(fd == -1){
        printf("Can't open the file\n");
        return -1;
    }

    while((Ret = read(fd,&info,sizeof(info))) != 0){
        //following while loop is for removing the Directory name before filename (Demo/)
        i=5; //Length of "Demo/" is 5
        while(info.Name[i] != '\0'){
            fName[(i-5)] = info.Name[i];
            i++;
        }

        //printf("File_Name: %s\n",fName);

        if(info.Size > 10)
        {
            printf("%s\n",fName);
        }
        memset(fName,0,sizeof(fName));
    }


    
    return 0;
}
