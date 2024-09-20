#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

    	int fd = open("records.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
    	if(fd==-1) {
        	perror("Error opening file");
        	return 1;
    	}
	int ticket_no = 10;
	write(fd,&ticket_no,sizeof(int));
	printf("Ticket_no initialized successfully\n");
}
