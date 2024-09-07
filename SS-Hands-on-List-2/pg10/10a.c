/*
NAME:10a.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
10. Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
DATE: 07 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void  handler(int signum){
	if(signum==SIGSEGV){
		printf("Segmentation fault triggered\n");
		exit(0);
	}

}


int main(){

	struct  sigaction sig;
	sig.sa_handler = handler;
	sig.sa_flags = 0;

	if(sigaction(SIGSEGV, &sig, NULL) == -1){
		perror("sigaction error\n");
		exit(0);
	}
	int *ptr = NULL;
	*ptr =42;

	return 0;

}

/* OUTPUT 

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg10$ ./a.out
Segmentation fault triggered

*/
