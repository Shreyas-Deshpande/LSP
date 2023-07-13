#include<stdio.h>// For printf
#include<fcntl.h> //for file mode definations(MACROS)
#include<unistd.h> //for close system call

int main(int argc, char* argv[]){\
    int fd =0;

    if(argc!=2){
        printf("Please enter the file name as command line argument\n");
        return -1;
    }


    fd = open(argv[1],O_RDONLY);

    if(fd == -1){
        printf("Can't Open File\n");
        return -1;
    }
    else{
        printf("File gets opened succesfully\n");
        printf("File Descriptor: %i\n",fd);
    }

    close(fd);
    return 0;
    
}
