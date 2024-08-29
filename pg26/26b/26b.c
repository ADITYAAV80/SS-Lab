/*
NAME: 26b.c
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
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char * argv[]){

	char *program = "./26bexec.out";
	char *arguments[] = {program, argv[1] , argv[2] , NULL};
	int ret = execvp(program,arguments);
	if (ret == -1){
		perror("execcvp error:");
	}
}

/* OUTPUT

1) Compile and execute the file: 26b.c

aditya@laptop:~/SS-Lab/pg26/26b$ ./26bexec.out 23 25
The sum of two numbers : 48

aditya@laptop:~/SS-Lab/pg26/26b$ ./26b.out 23 26
The sum of two numbers : 49

*/
