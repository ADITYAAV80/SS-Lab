/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM:
8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main( int argc, char * argv[]){

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
