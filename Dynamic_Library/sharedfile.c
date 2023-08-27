#include<stdio.h>
#include "sharedfile.h"

void Display()
{
    printf("Jay Ganesh...\n");
}


//To create .o file
//gcc -c -fPIC sharedfile.c

//to create .so file
//gcc -shared -o library.so sharedfile.o
