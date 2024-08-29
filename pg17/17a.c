/*
NAME: 17a.c
AUTHOR: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
17. Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
DATE: 17 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

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

/* OUTPUT

1) Compile and Execute the file : 17a.c

aditya@laptop:~/SS-Lab/pg17$ ./17a.out
File opened
Ticket number initialized to 10

*/
