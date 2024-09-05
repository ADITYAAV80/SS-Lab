/*
NAME: 27b.c
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

	printf("Using execlp:\n");
	int ret = execlp("ls", "ls", "-Rl", NULL);
	if (ret== -1){
		perror("execlp error");
	}
}

/* OUTPUT

1) Compile and execute : 27b.c

aditya@laptop:~/SS-Lab/pg27$ ./27b.out
Using execlp:
.:
total 40
-rw-r--r-- 1 root   root     745 Aug 29 23:14 27a.c
-rwxrwxr-x 1 aditya aditya 16040 Aug 29 23:12 27a.out
-rw-r--r-- 1 root   root     568 Aug 29 23:22 27b.c
-rwxrwxr-x 1 aditya aditya 16048 Aug 29 23:22 27b.out

*/
