#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void *Thread_1(void *ptr)
{
	// Thread -1 code
	int Ret = 0, fd1 = (int *)ptr;
	unsigned int iCount = 0, i = 0;
	char Buffer[600] = {'\0'};

	while ((Ret = read(fd1, Buffer, sizeof(Buffer))) != 0)
	{
		for (i = 0; i < Ret; i++)
		{
			if (Buffer[i] >= 'A' && Buffer[i] <= 'Z')
			{
				iCount++;
			}
		}
	}

	pthread_exit(iCount);
}

void *Thread_2(void *ptr)
{
	// Thread2 code here

	int Ret = 0, FD2 = (int *)ptr;
	unsigned int iCount = 0, i = 0;
	char Buffer[600] = {'\0'};

	printf("Insisde Thread-2\n");

	while ((Ret = read(FD2, Buffer, sizeof(Buffer))) != 0)
	{
		for (i = 0; i < Ret; i++)
		{
			if (Buffer[i] >= 'a' && Buffer[i] <= 'z')
			{
				iCount++;
				printf("%c", Buffer[i]);
			}
		}
		printf("\nEND\n");
	}

	pthread_exit(iCount);
}

int main(int argc, char *argv[])
{
	int Ret1 = 0, Ret2 = 0;
	int fd = 0;
	pthread_t TID1 = 0, TID2 = 0;
	int Cap_Count = 0, small_Count = 0;

	if (argc != 2) // Accept file name from command line arguements
	{
		printf("Insufficient Arguments\n");
		return -1;
	}

	/*Open the file in readonly mode*/
	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}

	Ret1 = pthread_create(&TID1, NULL, Thread_1, (int *)fd);
	if (Ret1 != 0)
	{
		printf("Unable to create thread\n");
		return -1;
	}

	Ret2 = pthread_create(&TID2, NULL, Thread_2, (int *)fd);

	if (Ret2 != 0)
	{
		printf("Unable to create second thred\n");
		return -1;
	}

	pthread_join(TID1, &Cap_Count);
	close(fd);
	pthread_join(TID2, &small_Count);

	// if ((Cap_Count == -1) || (small_Count == -1))
	// {
	// 	printf("Error occured while executing thread\n");
	// 	return -1;
	// }

	printf("Number of capital characters is: %u\n", Cap_Count);
	printf("number of small character is: %u\n", small_Count);

	close(fd);

	// Close the main thread

	pthread_exit(NULL);

	return 0;
}
