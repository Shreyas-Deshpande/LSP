#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>


int main(){

    int FD[2];
    
    char* Data = "This is data to be shared in Un-named Pipe";

    printf("Child is running\n");

    

        

   

    write(FD,Data,sizeof(Data));
    close(FD);

    unlink(path);
    printf("Data Written by child\n");
    return 0;
}
