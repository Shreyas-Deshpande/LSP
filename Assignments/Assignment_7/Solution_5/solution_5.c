/*Problem Staement:
*   Write a program which creates a static library which
*   contains file name from user and which displays the 
*   information of that file.
*/

#include "static_lib.h"

int main(int argc, char* argv[]){

    if(argc != 2){
        printf("Insufficient Arguements\n");
        return -1;
    }

    filegetInfo(argv[1]);

    return 0;
}


