/*
NAME: Aditya AV
ROLLNO: MT2024009
PROGRAM: 
3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<fcntl.h>
int main(){

	char *value="/home/aditya/linux_assignments/pg3/new_file.txt";
	mode_t mode = S_IRWXU;

	int fdval = creat(value,mode);
	if (fdval != -1){
		printf("File descriptor value: %d\n",fdval);
	}
	else{
		perror("error :");
	}
}
