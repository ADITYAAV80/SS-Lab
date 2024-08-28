/*
NAME: 7.c
NAME: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
7. Write a program to copy file1 into file2 ($cp file1 file2).
DATE: 10 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main( int argc, char *argv[]){

	if (argc<3){
		printf("Enter the file to be read and written in CLI\n");
		exit(0);
	}

	int fdr = open(argv[1], O_RDONLY);
	if ( fdr != -1 ){
		printf("File opened succesfully with fd : %d\n",fdr);
	}
	else{
		perror("Error:\n");
	}
	int fdw = open(argv[2], O_CREAT | O_WRONLY );
	if ( fdw != -1 ){
		printf("File opened succesfully with fd : %d\n",fdw);
	}
	else{
		perror("Error:\n");
	}
	while(1){
		char buf;
		int r =read(fdr,&buf,1);
		if( r == 0 ){
			break;
		}
		int w= write(fdw,&buf,1);
	}

	int fdrc = close(fdr);
	int fdwc = close(fdw);

	if (fdrc==-1 || fdwc==-1){
		printf("File not closed");
	}
}

/* OUTPUT

1) Create a file to read the data. File to be written to is optional.
2) Compile and execute : 7.c
3) While executing specify both the files in command line : ./7.out [file_to_be_read] [file_to_be_written_to]
4) Check contents of written file using cat or differences using diff


aditya@laptop:~/SS-Lab/pg7$ ./7.out
Enter the file to be read and written in CLI

aditya@laptop:~/SS-Lab/pg7$ ./7.out filer.txt filew.txt
File opened succesfully with fd : 3
File opened succesfully with fd : 4

aditya@laptop:~/SS-Lab/pg7$ cat filer.txt
Copy this to file 2

aditya@laptop:~/SS-Lab/pg7$ diff filer.txt filew.txt [empty output]

*/

