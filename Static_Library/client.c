#include<stdio.h>
#include "sharedfile.h"

int main(){
    int a =10, b =11, ret = 0;

    ret = Addition(a,b);
    printf("addition is: %d\n", ret);

    return 0;
}



/* Commands for Static library

To create .o file from .c file

    gcc -c sharedfile.c sharedfile.o

To generate .a file

    ar rcs sharedfiel.a sharedfile.o

To compile program using static library

    gcc -static client.c -o Myexe

*/
