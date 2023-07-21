/*Problem Staement:
*   Write a program which accepts the filename and offset from user
*   and remove all the data from that offset.
*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>


int main(int argc, char*argv[]){
    
    int Ret = 0;

    
    if(argc != 3){
        printf("Insufficient Arguments\n");
        return -1;
    }

    Ret = truncate(argv[1],(atoi(argv[2])));

    if(Ret == 0){
        printf("File truncated succesfully\n");
    }
    else{
        printf("File can't be truncated\n");
        return -1;
    }

    
    return 0;


}
