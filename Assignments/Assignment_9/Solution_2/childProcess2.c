#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>


#define IP_FILE "Hello.txt"
#define OP_FILE "Count.txt"

int main()
{

    int fd1 = 0, ret = 0, fd2 = 0;
    char Buff[350] = {'\0'};
    char cCount[8] = {'\0'};
    int iCount = 0, i = 0;

    fd1 = open(IP_FILE, O_RDONLY);

    while ((ret = read(fd1, Buff, sizeof(Buff))) != 0)
    {
        for (i = 0; i < ret; i++)
        {
            if (Buff[i] >= 'A' && Buff[i] <= 'Z')
            {
                iCount++;
            }
        }
        //printf("Read %d bytes from file\n", ret);
    }

    memset(Buff,0,sizeof(Buff));
    ret =0;
    close(fd1);
    
    ret = sprintf(Buff,"Number of capital letters in %s is: %d\n",IP_FILE,iCount);

    fd2 = open(OP_FILE,O_RDWR|O_APPEND);
    write(fd2,Buff,ret);
    return 0;
}
