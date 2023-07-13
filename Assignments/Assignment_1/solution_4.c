/*
*Problem Statement:
*   Write a program which accept file name from user 
*   and print all information about that file.
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

struct stat ob_stat;

int main(int argc, char* argv[]){

    int fd =0;

    if(argc!= 2){
        printf("Enter the file name as argument\n");
        return -1;
    }

    fd = open(argv[1],O_RDONLY);

    if(fd == -1){
        printf("Can't open the file you specified\n");
        return -1;
    }
    else{
        printf("File gets opened succesfully\n");

        stat(argv[1],&ob_stat);

        printf("\n*********************************\n");
        printf("\t   File Info\n");
        printf("*********************************\n");
        printf("File Name: \t\t%s\n",argv[1]);
        printf("File inode: \t\t%i\n",ob_stat.st_ino);
        printf("File Size: \t\t%i\n",ob_stat.st_size);
        printf("Number of 512B Blocks: \t%i\n",ob_stat.st_blocks);
        printf("Block Size: \t\t%i\n",ob_stat.st_blksize);
        printf("Link Count: \t\t%i\n",ob_stat.st_nlink);
        printf("File System Number: \t%i\n",ob_stat.st_dev);
        printf("User ID: \t\t%i\n",ob_stat.st_uid);
        printf("Group ID: \t\t%i\n",ob_stat.st_gid);

        printf("User Permissions: \t");
        if((ob_stat.st_mode & S_IRUSR)){
            printf("r ");
        }
        else{
            printf("- ");
        }
        if((ob_stat.st_mode & S_IWUSR)){
            printf("w ");
        }
        else{
            printf("- ");
        }
        if((ob_stat.st_mode & S_IXUSR)){
            printf("x\n");
        }
        else{
            printf("-\n");
        }

        printf("Group Permissions: \t");
        if((ob_stat.st_mode & S_IRGRP)){
            printf("r ");
        }
        else{
            printf("- ");
        }
        if((ob_stat.st_mode & S_IWGRP)){
            printf("w ");
        }
        else{
            printf("- ");
        }
        if((ob_stat.st_mode & S_IXGRP)){
            printf("x\n");
        }
        else{
            printf("-\n");
        }

        printf("Other Permissions: \t");
        if((ob_stat.st_mode & S_IROTH)){
            printf("r ");
        }
        else{
            printf("- ");
        }
        if((ob_stat.st_mode & S_IWOTH)){
            printf("w ");
        }
        else{
            printf("- ");
        }
        if((ob_stat.st_mode & S_IXOTH)){
            printf("x\n");
        }
        else{
            printf("-\n");
        }

        printf("*********************************\n\n");

    }

    return 0;
}
