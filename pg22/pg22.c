/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM:
22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main(int argc,char *argv[]){

	int fd = open(argv[1], O_CREAT | O_RDWR);
	if (fd!=-1){
		printf("The file is opened\n");
	}
	else{
		perror("Error");
	}
	if(fork()){

		char buffer[] = "Hi, I am a child process writing to a file\n";
		int w = write(fd,buffer,sizeof(buffer));
		if (w <0){
			perror("Child process couldn't write to a file");
		}
	}
	else{

		char buffer[] = "Hi, I am a parent process writing to a file\n";
		int w = write(fd,buffer,sizeof(buffer));
		if (w <0){
			perror("Parent process couldn't write to a file");
		}
	}
	if(!close(fd)){
		perror("Error closing file");
	}
}
	
