#include "static_lib.h"

void filegetInfo(char cName[30]){
    //int fd = 0;
    struct stat sobj;

    stat(cName,&sobj);

    printf("File Name: %s\n",cName);
    printf("File Size: %ld\n",sobj.st_size);
    printf("inode Number:  %ld\n",sobj.st_ino);
    printf("Group ID: %d\n",sobj.st_gid);

    return;    
}
