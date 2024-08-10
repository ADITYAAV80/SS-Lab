/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM:
7. Write a program to copy file1 into file2 ($cp file1 file2).
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main( int argc, char *argv[]){

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
	return 0;
}
