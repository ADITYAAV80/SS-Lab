/*
NAME: 26a.c 
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

int main() {

	char *program = "./26aexec.out";
	char *argv[]={program,NULL};
	int ret = execvp(program,argv);
	if (ret==-1){
		perror("execvp error");
		exit(0);
	}
}

/* OUTPUT

1) Compile and execute the file : 26a.c
2) It'll execute 26aexec.out

aditya@laptop:~/SS-Lab/pg26/26a$ ./26aexec.out
Hello World

aditya@laptop:~/SS-Lab/pg26/26a$ ./26a.out
Hello World

*/
