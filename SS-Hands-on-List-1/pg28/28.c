/*
NAME: 28.c
AUTHOR: ADITYA AV
ROLLNO: MT2024009
PROGRAM:
28. Write a program to get maximum and minimum real time priority.
DATE: 30 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<sched.h>

int main(int argc, char *argv[]){

	int maxpriority = sched_get_priority_max(SCHED_FIFO);
	int minpriority = sched_get_priority_min(SCHED_FIFO);

	if ( maxpriority == -1 || minpriority == -1 ){
		perror("Error");
	}

	printf("Maximum real time priority : %d\n",maxpriority);
	printf("Minimum real time priority : %d\n",minpriority);
}

/* OUTPUT

1) Compile and execute the program : 28.c

aditya@laptop:~/SS-Lab/pg28$ ./28.out
Maximum real time priority : 99
Minimum real time priority : 1

*/
