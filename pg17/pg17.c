#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[]){

	int ticket_no = 10;
	int fd = open("file.txt", O_CREAT | O_RDWR, 0777);
	if (fd==-1){
		perror("Error opening file\n");
	}
	else{
		printf("File opened\n");
	}
	int w = write(fd,&ticket_no,sizeof(int));
	if(w==-1){
		perror("write error\n");
	}
	else{
		printf("Ticket number initialized to %d\n",ticket_no);
	}
	close(fd);
}
