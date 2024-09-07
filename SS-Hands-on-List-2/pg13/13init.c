/*
NAME:13.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
DATE: 07 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>

int main(){

	printf("My PID is %d",getpid());
	while(1){};

}
