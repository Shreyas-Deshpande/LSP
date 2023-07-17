/*Problem Statement:
*   write a program which accepts the filename from user
*   which contains information of employee,
*   we have to read all the contents of the file.
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


int main(int argc, char *argv[]){
    int fd = 0, ret = 0;
    struct student sobj;
    if(argc != 2){
        printf("Insufficient arguments\n");
        return -1;
    }
    
    fd = open(argv[1],O_RDONLY);

    ret = read(fd,&sobj,sizeof(sobj));

    close(fd);

    printf("Roll Number: %d\n",sobj.RollNo);
    printf("Name:  %s\n",sobj.Name);
    printf("Marks: %f\n",sobj.Marks);
        
    return 0;
}
