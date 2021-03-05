#include <stdio.h> 
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	FILE *file2;
	int fifoserver,fifoclient;
	char str[256];
	char *buff;
	char *choices;
	printf("Welcome  to a  simple chat application\n\n");
	if(fork() == 0){   
		while(1){
			 choice = malloc(10*sizeof(char));
			 scanf("%s",choices);
			 fifo_server=open("fifoserver",O_RDWR);
			 write(fifoserver,choices,sizeof(choices));
		}    
	}
	else{
		while(1){
			fifoclient = open("fifoclient",O_RDWR);
			read(fifoclient,choices,sizeof(choices));
			printf("%s\n",choices);
		}
	}
	close(fifoserver); 
	close(fifoclient);  
}
