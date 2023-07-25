#include "sharedlib.h"

void Add(int iNo1,int iNo2)
{
    printf("Addition is: %d\n", (iNo1 + iNo2));
}

void Sub(int iNo1,int iNo2)
{   
    if(iNo1 < iNo2){
        printf("First number should be greater than second number\n");
        return ;
    }
    
    printf("Subtraction is: %d\n",(iNo1 - iNo2));
}

void Mul(int iNo1,int iNo2){
    printf("Multiplication is: % d\n",(iNo1 * iNo2));
}

void Div(int iNo1,int iNo2){
    if(iNo1 < iNo2){
        printf("iNo1 should be greater than iNo2\n");
        return;
    }

    printf("Division is: %f\n",(float)(iNo1/iNo2));
}
