/*
NAME:31a.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
31. Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
DATE: 18 SEP 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>

int main() {

        sem_t binary_semaphore;
    	if(sem_init(&binary_semaphore, 0, 1)==-1){
		perror("sem_init");
		exit(0);
	}
    	printf("Binary semaphore created and initialized.\n");
    	sem_destroy(&binary_semaphore);

}

/* OUTPUT

aditya@laptop:~/SS-Lab/SS-Hands-on-List-2/pg31$ ./31a.out
Binary semaphore created and initialized.

*/
