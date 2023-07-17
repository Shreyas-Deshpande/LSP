/*Problem Statement: 
*   Write a program which writes structure in file. 
*   Structure should contain information about student.   
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

struct student{
    int RollNo;
    char Name[20];
    float Marks;
};

int main(int argc, char* argv[]){
    int fd = 0;
    struct student sobj;
    
    if(argc != 2){
        printf("Insufficient Arguments\n");
        return -1;
    }

    sobj.RollNo = 12;
    sobj.Marks = 86.34f;
    strcpy(sobj.Name,"Suhas");

    fd = creat(argv[1],0744);

    if(fd == -1){
        printf("File can't be created\n");
        return -1;
    }
    
    write(fd,&sobj,sizeof(sobj));

    close(fd);

    return 0;
}
