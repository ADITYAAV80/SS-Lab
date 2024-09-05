/*
NAME: 26bexec.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
26. Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
DATE: 29 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

	if (argc<3){
		printf("Please enter two number as arguments in CLI\n");
		exit(0);
	}
	int x = atoi(argv[1]);
	int y = atoi(argv[2]);
	printf("The sum of two numbers : %d\n",(x+y));

}
