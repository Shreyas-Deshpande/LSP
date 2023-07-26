#include "sharedlib.h"

void filecmp(char* file1, char* file2){
    int fd1 =0, fd2 = 0;
    int Ret = 0;
    char Buff_1[BLOCKSIZE] = {'\0'};
    char Buff_2[BLOCKSIZE] = {'\0'};
    struct stat objstat1, objstat2;



    fd1 = open(file1,O_RDONLY);
    fd2 = open(file2,O_RDONLY);

    fstat(fd1,&objstat1);
    fstat(fd2,&objstat2);

    if(objstat1.st_size != objstat2.st_size){
        printf("Files are not identical (Size Mis-match)\n");
        return;
    }

    while((Ret = read(fd1,Buff_1,sizeof(Buff_1))) != 0){
        
        Ret = read(fd1,Buff_2,sizeof(Buff_2));

        if((memcmp(Buff_1,Buff_2,Ret)) != 0){
            break;
        }
    }

    if(Ret!=0){
        printf("Files are not identical(Content Mismatch)\n");
    }
    else
    {
        printf("Files are identical\n");
    }

}
