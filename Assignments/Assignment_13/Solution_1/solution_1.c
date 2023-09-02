/*
 * Write a program which creates two processes as reader
 * and writer and those processes should communicate with
 * each other using FIFO
 */
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc, char* argv[])
{
	int fd = 0, ret = 0;
	char* fifo_path = "/tmp/mypipe";

	fd = mkfifo(fifo_path, 0666);

	if(fd == -1)
	{
		printf("Unable to create named pipe\n");
		return -1;
	}

	//create new process using fork and execl
	ret = fork();
	if(ret == 0){
		//from child process read the pipe;
		execl("./read_fifo","NULL",NULL);
	}
	else{
		printf("Server is runnig and writing data in named pipe\n");
		fd = open(fifo_path,O_WRONLY);
		write(fd,"This is shared data.",20);
		close(fd);
		printf("Data wriiten in named pipe succesfully\n");
		unlink(fifo_path);
	}
	return 0;
}

