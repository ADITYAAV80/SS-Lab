/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM:
4. Write a program to open an existing file with read write mode. Try O_EXCL flag also. 
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char* argv[]){

	int ret = open(argv[1], O_CREAT | O_RDWR  | O_EXCL, 0700);
	if (ret != -1){
		printf("File opened successfully\n");
	}
	else{
		perror("error :");
	}
}
