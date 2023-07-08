#include<stdio.h>

int main(int argc, char*argv[]){
    int iNO1 = 0, iNo2 = 0;
    int iAns =0;

    printf("Enter First Number: \n");
    scanf("%d",&iNO1);

    printf("Enter Second Number: \n");
    scanf("%d",&iNo2);

    iAns = iNO1 + iNo2;

    printf("Addition is : %d\n", iAns);

    return 0;
}
