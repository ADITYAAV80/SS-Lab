/*
NAME:11.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
DATE: 07 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main(){

	struct sigaction sig;
	sig.sa_handler = SIG_IGN;
	sig.sa_flags =0;

	printf("Ignoring ctrl+c\n");
	if(sigaction(SIGINT, &sig,NULL) == -1){
		perror("sigaction");
		exit(0);
	}

	for(int i=0;i<6;i++){
		printf("%d seconds left\n",5-i);
		sleep(1);
	}

	printf("Default action triggered\n");

	sig.sa_handler = SIG_DFL;
	if(sigaction(SIGINT, &sig,NULL) == -1){
		perror("sigaction");
		exit(0);
	}
	while(1){};
	return 0;
}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg11$ ./a.out
Ignoring ctrl+c
5 seconds left
^X4 seconds left
^X3 seconds left
2 seconds left
^C1 seconds left
^C0 seconds left
^CDefault action triggered
^C

*/
