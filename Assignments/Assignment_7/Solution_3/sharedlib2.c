#include "sharedlib2.h"

void checkPerfect(int iNo){
    int i = 0, temp =0;

    for(i =1; i<=(iNo/2);i++){
        if((iNo%i) == 0){
            temp += i;
        }
    }
    
    if(temp == iNo){
        printf("%d is Perfect Number\n",iNo);
    }
    else{
        printf("%d is not an Perfect Number\n",iNo);
    }

    return;
}
