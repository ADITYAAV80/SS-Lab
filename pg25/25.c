/*
NAME: 25.c
AUTHOR: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
25. Write a program to create three child processes. The parent should wait for a particular 
child (use waitpid system call).
DATE: 22 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char *argv[]){

	int status;

	int f1 = fork();
	if(f1==0){
		printf("Child 1 created with pid %d\n",getpid());
		sleep(2);
		printf("Child 1 exited\n");
		exit(0);
	}
	int f2 = fork();
	if(f2==0){
		printf("Child 2 created with pid %d\n",getpid());
		sleep(20);
		printf("Child 2 exited\n");
		exit(0);
	}
	int f3=fork();
	if(f3==0){
		printf("Child 3 created with pid %d\n",getpid());
		sleep(1);
		printf("Child 3 exited\n");
		exit(0);
	}

	int w = waitpid(f2,&status,0);
	if (w<0){
		perror("error waitpid :");
	}
	printf("Parent process has finished execution\n");
}

/* OUTPUT

1) Compile and execute : 25.c
2) Replace the first argument in waitpid for it to wait for different child

aditya@laptop:~/SS-Lab/pg25$ ./25.out
Child 1 created with pid 24682
Child 2 created with pid 24683
Child 3 created with pid 24684
Child 3 exited
Child 1 exited
Child 2 exited
Parent process has finished execution

*/
