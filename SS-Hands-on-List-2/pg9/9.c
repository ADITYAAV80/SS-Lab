/*
NAME:9.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
9. Write a C program to ignore a SIGINT signal then reset the 
default action of the SIGINT signal - Use signal system call.
DATE: 07 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int main(){

	printf("Ignoring ctrl+c\n");
	signal(SIGINT,SIG_IGN);

	for (int i = 5; i > 0; i--) {
        printf("%d seconds left\n", i);
        fflush(stdout);
        sleep(1);  
    	}

	printf("Default action triggered\n");
	signal(SIGINT,SIG_DFL);

	while(1){};

}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg9$ ./a.out
Ignoring ctrl+c
5 seconds left
4 seconds left
^C3 seconds left
2 seconds left
^C1 seconds left
^CDefault action triggered
^C


*/
