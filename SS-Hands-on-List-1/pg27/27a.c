/*
NAME: 27a.c
AUTHOR: Aditya AV
ROLLNO: MT2024009
PROGRAM:
27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
DATE: 29 AUG 2024
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(){

	printf("Using execl:\n");
	int ret = execl("/bin/ls","ls","-Rl",NULL);
	if (ret==-1) {
		perror("execl");
	}
}

/* OUTPUT

aditya@laptop:~/SS-Lab/pg27$ ./27a.out
Using execl:
.:
total 20
-rw-r--r-- 1 root   root     559 Aug 29 23:11 27a.c
-rwxrwxr-x 1 aditya aditya 16040 Aug 29 23:12 27a.out

*/
