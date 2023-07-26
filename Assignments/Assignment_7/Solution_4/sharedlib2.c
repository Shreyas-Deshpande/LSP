#include "sharedlib2.h"

void factorial(int iNum)
{
    int i = 0;
    unsigned long long Factorial = 1;

    for (i = 1; i <= iNum; i++)
    {
        Factorial = Factorial * i;
        
    }

    printf("Factorial of %d is %llu \n", iNum, Factorial);

    return;
}
