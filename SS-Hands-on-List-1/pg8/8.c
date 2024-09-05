/*
NAME: 8.c
NAME: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
DATE: 10 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main( int argc, char * argv[]){

	if (argc<=1){
		printf("Please enter file name in CLI\n");
		exit(0);
	}

	int fd = open( argv[1], O_RDONLY);
	if ( fd != -1){
		printf("File opened successfully with fd: %d\n",fd);
	}
	else{
		perror("Error:\n");
	}
	while(1){
		char c;
		int r = read(fd,&c,1);
		if (r==0){
			break;
		}
		if (c=='\n'){
			while(1){
				char cfe;
				int icfe = read(0,&cfe,1);
				if (cfe=='\n'){
					break;
				}
			}
		}
		else{
			write(1,&c,1);
		}
	}
	int fdc=close(fd);
	if (fdc == -1){
		printf("File not closed");
	}
}

/* OUTPUT

1) Create a file contaning new lines
2) Compile and Run : 8.c
3) Specify file in command line during execution : ./8.out [file name to be read from]

aditya@laptop:~/SS-Lab/pg8$ ./8.out
Please enter file name in CLI
aditya@laptop:~/SS-Lab/pg8$ ./8.out file.txt
File opened successfully with fd: 3
Hello
This
is
File
To
be
Copied

*/

