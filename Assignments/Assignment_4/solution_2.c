/*Problem Statement:
*   Write a program which accepts directory name from user and 
*   creates directory of that name.
*/

#include<stdio.h>
#include<sys/stat.h>
#include<sys/dir.h>

int main(int argc, char* argv[]){
    int ret = 100;

    if(argc != 2){
        printf("Insufficient arguments\n");
        return -1;
    }

    ret = mkdir(argv[1],0777);

    if(ret<0){
        printf("Directory creation failed\n");
        return -1;
    }
    else{
        printf("Directory of name %s created succesfully\n",argv[1]);
    }



    return 0;
}
