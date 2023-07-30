#include<stdio.h>
#include<sys/resource.h>

int main(){
    
    printf("Priority of current porcess is: %d\n",getpriority(PRIO_PROCESS,0));

    return 0;
}
