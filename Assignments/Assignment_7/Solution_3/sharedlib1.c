//Checks Number is prome or not

#include "sharedlib1.h"

void checkPrime(int iNo){
    int i =0;

    if(iNo == 0 || iNo == 1){
        printf("%d is not prime number\n",iNo);
        return;
    }

    for(i =2; i<=(iNo/2);i++){
        if((iNo % i) == 0){
            break;
        }
    }

    if(i > (iNo/2)){
        printf("%d is a Prime Number\n",iNo);
    }
    else{
        printf("%d is not a Prime Number\n",iNo);
    }

    return;
}
