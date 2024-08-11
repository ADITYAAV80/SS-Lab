/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM:
10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main( int argc, char * argv[]){

	int i = 10;
	int fd = open(argv[1], O_CREAT|O_RDWR, 0666);
	if (fd != -1){
		printf("File opened successfully with fd: %d\n",fd);
	}
	else{
		perror("Error:");
	}
	char buf[10];
	printf("Enter text of 10 bytes : ");
	scanf("%s",buf);
	int w = write(fd,buf,10);
	if (w>=0){
		printf("%d bytes written\n",w);
	}
	else{
		perror("Error:");
	}
	int offset = lseek(fd,10,SEEK_CUR);
	if (offset == (off_t)-1) {
       		perror("Error using lseek");
       		close(fd);
        	exit(EXIT_FAILURE);
   	} 
	else {
        	printf("lseek moved the file pointer to position: %d\n",offset);
    	}
	char buf2[10];
	printf("Enter second of 10 bytes:");
	scanf("%s",buf2);
	int ws = write(fd,buf2,10);
	if (ws>=0){
		printf("%d bytes written\n",ws);
	}
	else{
		perror("Error:");
	}
	close(fd);
}
