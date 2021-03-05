#include<stdio.h> 
#include<fcntl.h>
#include<stdlib.h>
int main()
{
	int file1,file3;
	int fd1;
	char str[256];
	char temp[4];
	char temp1[4];
	file1 = mkfifo("fifo_server",0666); 
	file3 = mkfifo("fifo_client",0666);
	printf("FIFO  Server  and  child  created!\n ");
}
