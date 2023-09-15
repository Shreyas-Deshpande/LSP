#pragma once

#include <stdio.h>  // for printf
#include <fcntl.h>  //for mode defination
#include <string.h> // for strcmp
#include <unistd.h> //For close

int Open_File(char *Name, char *Mode);
int Close_File(int FD);
