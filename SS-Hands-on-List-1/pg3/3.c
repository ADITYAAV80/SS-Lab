/*
NAME: 3.c
NAME: ADITYA AV
ROLLNO: MT2024009
PROGRAM: 
3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call
DATE: 8AUG 2024

------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<fcntl.h>
int main(){

	char *value="new_file.txt";
	mode_t mode = S_IRWXU;

	int fdval = creat(value,mode);
	if (fdval != -1){
		printf("File descriptor value: %d\n",fdval);
	}
	else{
		perror("error :");
	}
}

/* OUTPUT

1) Compile and execute the program : 3.c

aditya@laptop:~/SS-Lab/pg3$ ./3.out
File descriptor value: 3

*/
